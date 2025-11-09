## 🧪 Dataset Overview and Preparation Pipeline 

The anomaly detection models are trained using telemetry collected from the **OPS-SAT ADCS** subsystem.  
The data undergoes a structured pipeline consisting of **scaling → feature extraction → optimization** to produce a compact, high-information training dataset suitable for on-board inference.
The data is the values of a channel over a period of time(segment)
#this a plot of the values versus the time of one of the nine sensors(anomaly and normal) :

<div style="display: flex; justify-content: center; gap: 10px;">
  <img src="https://github.com/user-attachments/assets/72199fbb-8196-400b-869c-7ca57be7cb10" width="45%" />
  <img src="https://github.com/user-attachments/assets/6b508d5e-8765-4d84-a95a-8d283118b0bb" width="45%" />
</div>

the data contains : 

<img width="933" height="208" alt="image" src="https://github.com/user-attachments/assets/8b6389c3-ba08-412b-b845-b1e96ada1261" />

---

### A. Data Directory Structure  
**Location:** `ML_models(detection)/OPS-SAT-NN`

| File Name | Description | Source / Transformation |
|----------|-------------|-------------------------|
| `/data/segments.csv` | Raw ADCS telemetry data | Direct extraction from OPS-SAT system |
| `/data/segmentsT.csv` | Scaled telemetry values | Numerical scaling applied by multiplying micro-signals by \(10^6\) |
| `datatransformation.py` | Data preprocessing script | Performs cleaning and scaling |
| `/data/__dataset.csv` | Feature-extracted dataset | Created after statistical and signal processing feature extraction |
| `dataset_generator.py` | Feature extraction automation script | Segments signals and computes features |
| `/data/ready_data.csv` | Final optimized dataset for model training | Obtained after correlation filtering and feature reduction |

---

### B. Detailed Feature Extraction Process 🛠️

Telemetry data is segmented into fixed-length windows, and each segment is transformed into a feature vector.  
The extracted features fall into four conceptual categories:

| Feature Category | Example Features | Purpose |
|------------------|-----------------|---------|
| **Basic Statistics** | mean, variance, skew, kurtosis | Capture distribution and behavior trends |
| **Rate of Change** | diff_var, diff2_var | Describe short-term stability and smoothness |
| **Signal Complexity** | n_peaks, smooth10_n_peaks, diff_peaks | Detect abrupt changes and oscillation patterns |
| **Temporal / Derived** | duration, gaps_squared | Capture timing irregularities and sampling consistency |

This structured representation ensures anomalies can be detected based on both **shape** and **behavior** of the signal rather than raw amplitude alone.

---

### C. Final Optimization (Correlation Filtering) 🎯

To reduce dimensionality and avoid redundant information affecting the model, a **correlation matrix** was computed across all extracted features.  
Highly correlated features were removed to improve:

- Model generalization
- Memory efficiency (critical for embedded deployment)
- Training stability

**Examples of removed redundant features include:**
len_weighted, diff2_var, var_div_len, var_div_duration, diff2_peaks, std

<img width="1048" height="779" alt="image" src="https://github.com/user-attachments/assets/383b09c5-6073-4798-828a-78b51ce69848" />


# 🧠 Anomaly Detection Model Comparison

This directory contains the notebooks, data, and source code used to train and validate the primary **Anomaly Detection Model** for the **OPS-SAT ADCS** system.  
The final deployed model is an **Artificial Neural Network (ANN)**, selected after comparison with a **Random Forest (RF)** classifier.

---

## 📊 Performance Comparison

### 1. Model Efficacy Metrics

The ANN model was chosen due to its stronger **F1 Score** and balanced performance — especially important for detecting anomalies where minimizing false negatives is critical.

| Metric | ANN Model *(Final Choice)* | Random Forest Model |
|-------|----------------------------|---------------------|
| **Accuracy** | **95.65%** | 94.67% |
| **F1 Score** | **89.10%** | 85.95% |
| **AUC (Area Under Curve)** | **97.63%** | 97.50% |

---

### 2. Embedded Resource Footprint  
*Estimated on Cortex-M4F @ 80MHz*

The ANN model is optimized for real-time inference on the **STM32F429** using the **CubeAI** framework.

| Metric | ANN Model | RF Model |
|--------|-----------|----------|
| **Total Latency** | **2 ms** | Not reported |
| **RAM Usage** | **0.2 KB** | Not reported |
| **Flash Usage** | **34.7 KB** | Not reported |

---

## 📉 Confusion Matrix Analysis

| **Artificial Neural Network (ANN)** | **Random Forest (RF)** |
|---|---|
| <img src="https://github.com/user-attachments/assets/014a1879-1b5f-4f2e-ac02-f0a412282ac2" width="350"> | <img src="https://github.com/user-attachments/assets/2f41fc5f-e1b2-461d-95f4-9d60bd418ead" width="350"> |

**Left:** ANN shows very low false positives (only 4) and strong anomaly detection sensitivity.  
**Right:** RF produces fewer false positives but detects significantly fewer anomalies, reducing reliability in ADCS monitoring.


---

## 🎯 Conclusion

The **Artificial Neural Network (ANN)** was selected as the final model due to:

- Higher **F1 Score** and **AUC**
- Better balance between detecting anomalies and avoiding false alarms
- **Significantly smaller inference footprint** when deployed on embedded hardware
- Real-time performance (**~2 ms latency**) on STM32F429 via **CubeAI**

This makes the ANN model both **accurate** and **deployment-efficient**, meeting the operational constraints of onboard satellite ADCS systems.

---

---

## 🧠 Artificial Neural Network (ANN) Architecture 

The anomaly detection is executed using a **Multi-Layer Perceptron (MLP)** optimized for **fast, low-power edge inference** on the STM32F429 microcontroller.  
The network performs a **binary classification** to determine whether a given ADCS telemetry segment is **Normal** or **Anomalous**.

---

### A. Input Layer — Feature Vector

The input to the ANN is the **feature-engineered vector** produced during the dataset preparation pipeline.

| Component | Description |
|----------|-------------|
| **Data Source** | `ready_data.csv` (final filtered training dataset) |
| **Input Structure** | Numerical feature vector (~11–13 features after correlation filtering) |
| **Content** | Statistical and temporal descriptors derived from ADCS channels (Magnetometer X/Y/Z and Photodiodes PD1–PD6) |

Each input feature captures meaningful signal behavior such as mean, variance, kurtosis, peak counts, or segment duration.

---

### B. Hidden Layers — Sequential Processing

The ANN uses a **fully connected deep neural architecture**:

| Layer | Neurons | Activation |
|------|---------|------------|
| Hidden Layer 1 | 128 | ReLU |
| Hidden Layer 2 | 64 | ReLU |
| Hidden Layer 3 | 32 | ReLU |

This depth enables the model to learn **progressively complex patterns**, allowing reliable discrimination between normal and anomalous ADCS behavior.

---

### C. Output Layer — Binary Decision

| Output Component | Description |
|------------------|-------------|
| Output Neurons | 1 |
| Activation Function | Sigmoid |
| Output Meaning | Probability of anomaly |

Interpretation:

| Output Value | Meaning |
|-------------|---------|
| **≈ 0** | System operating normally |
| **≈ 1** | **Anomaly Detected** → triggers corrective action |

---

### ✅ Key Deployment Benefits:
| Metric | Value |
|-------|-------|
| **Classification Accuracy** | 95.65% |
| **F1 Score** | 89.1% |
| **Latency on STM32F429** | ~2 ms |
| **RAM Usage** | ~0.2 KB |
| **Flash Footprint** | ~34.7 KB |

This makes the ANN **highly efficient** and **mission-ready** for **real-time autonomous CubeSat operations**.

<img width="354" height="1105" alt="image" src="https://github.com/user-attachments/assets/be273db6-7474-4e1a-8579-1a93560f8be3" />

---

