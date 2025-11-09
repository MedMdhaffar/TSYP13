import pandas as pd

df = pd.read_csv("./data/segments.csv")
df["value"] = df["value"] * 1e6  # rescale micro-values
df.to_csv("./data/segmentsT.csv", index=False)