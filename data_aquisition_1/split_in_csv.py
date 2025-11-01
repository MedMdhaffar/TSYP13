import pandas as pd
import os
import json

# === 1. Load dataset ===
df = pd.read_csv("segments.csv")

# === 2. Keep relevant columns ===
df = df[["timestamp", "value", "anomaly", "sampling", "segment", "train"]]

df = df[df["sampling"] == 5] 

print(df.head())

# === 3. Create directories ===
base_dir = "output_data"
train_dir = os.path.join(base_dir, "training")
test_dir = os.path.join(base_dir, "testing")
os.makedirs(train_dir, exist_ok=True)
os.makedirs(test_dir, exist_ok=True)

# === 4. Prepare label info containers ===
train_label_info = {"version": 1, "files": []}
test_label_info = {"version": 1, "files": []}
global_label_info = {"version": 1, "files": []}

# === 5. Group by segment and export ===
for (segment_id, segment_data) in enumerate(df.groupby("segment")):
    # Determine train/test
    train_flag = int(segment_data[1]["train"].iloc[0])
    out_dir = train_dir if train_flag == 1 else test_dir
    category = "training" if train_flag == 1 else "testing"

    # Extract label
    if segment_data[1]["anomaly"].iloc[0] == 0:
        label_value = "normal"
    else:
        label_value = "anomaly"

    # === Convert timestamp ===
    # Each file should start at 0 ms with constant intervals based on sampling rate
    sampling_ms = int(segment_data[1]["sampling"].iloc[0]) * 1000  # 1→1000 ms, 5→5000 ms
    num_samples = len(segment_data[1])
    timestamps = pd.Series(range(0, num_samples * sampling_ms, sampling_ms))


    # Prepare data for CSV
    feature_data = pd.DataFrame({
        "timestamp": timestamps,
        "Xsensor": segment_data[1]["value"].values * 1e6  # scale to avoid Edge Impulse graph error
    })

    # === Build filename according to Edge Impulse convention ===
    unique_id = segment_data[0]  
    filename = f"{label_value}.{unique_id}.csv"
    file_path = os.path.join(out_dir, filename)

    # === Save the feature CSV ===
    feature_data.to_csv(file_path, index=False)

    # === Create entry for info.labels ===
    entry = {
        "path": f"{category}/{filename}",
        "name": filename,
        "category": category,
        "label": {
            "type": "label",
            "label": label_value
        }
    }

    # Append to label structures
    if train_flag == 1:
        train_label_info["files"].append(entry)
    else:
        test_label_info["files"].append(entry)

    global_label_info["files"].append(entry)

    print(f"✅ Saved {filename} ({category}, label={label_value})")
    

# === 6. Save info.labels files ===
with open(os.path.join(train_dir, "info.labels"), "w") as f:
    json.dump(train_label_info, f, indent=4)

with open(os.path.join(test_dir, "info.labels"), "w") as f:
    json.dump(test_label_info, f, indent=4)

# Global info.labels (both train + test)
with open(os.path.join(base_dir, "info.labels"), "w") as f:
    json.dump(global_label_info, f, indent=4)

# === 7. Summary ===
print("\n✅ Export completed successfully!")
print(f"Training segments: {len(train_label_info['files'])}")
print(f"Testing segments: {len(test_label_info['files'])}")
print(f"Total files listed in global info.labels: {len(global_label_info['files'])}")
