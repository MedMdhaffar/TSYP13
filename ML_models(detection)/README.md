# 🛰️ OPS-SAT ADCS Anomaly Detection

## I. Dataset Overview and Preparation Pipeline

The anomaly detection models are trained using telemetry collected from the **OPS-SAT ADCS** subsystem.  
The data undergoes a structured pipeline consisting of **scaling → feature extraction → optimization** to produce a compact, high-information dataset suitable for on-board inference.

The data corresponds to the values of each sensor channel over time (segments).

### A. Data Directory Structure

**Location:** `ML_models(detection)/OPS-SAT-NN`

| File Name | Description | Source / Transformation |
|----------|-------------|-------------------------|
| `/data/segments.csv` | Raw ADCS telemetry data | Extracted directly from OPS-SAT |
| `/data/segmentsT.csv` | Scaled telemetry values | Scaled by multiplying micro-signals by \(10^6\) |
| `datatransformation.py` | Data preprocessing script | Performs cleaning and scaling |
| `/data/__dataset.csv` | Feature-extracted dataset | Output after statistical feature extraction |
| `dataset_generator.py` | Feature extraction automation script | Segments signals and computes features |
| `/data/ready_data.csv` | Final optimized dataset | Output after correlation filtering |

---

### B. Feature Extraction Process

Each telemetry segment is transformed into a feature vector.  
Features are grouped into four categories:

| Feature Category | Example Features | Purpose |
|------------------|-----------------|---------|
| Basic Statistics | mean, variance, skew, kurtosis | Capture distribution shape |
| Rate of Change | diff_var, diff2_var | Detect short-term variability |
| Signal Complexity | n_peaks, smooth10_n_peaks, diff_peaks | Measure oscillatory behavior |
| Temporal / Derived | duration, gaps_squared | Capture timing irregularities |

---

### C. Feature Optimization (Correlation Filtering)

A correlation matrix was computed to identify and remove redundant and highly correlated features to improve:

- Model generalization  
- Memory efficiency  
- Training stability  

Examples of removed redundant features:  
`len_weighted`, `diff2_var`, `var_div_len`, `var_div_duration`, `diff2_peaks`, `std`

---

## II. Anomaly Detection Model Comparison

The directory includes notebooks and source code for training and evaluating two models:  
A **Multi-Layer Perceptron (ANN)** and a **Random Forest (RF)** classifier.

### A. Performance Metrics

| Metric | ANN (Final Model) | Random Forest |
|-------|------------------|---------------|
| Accuracy | **95.65%** | 94.67% |
| F1 Score | **89.10%** | 85.95% |
| AUC | **97.63%** | 97.50% |

### B. Embedded Resource Footprint (STM32F429, Cortex-M4F @ 80MHz)

| Metric | ANN Model | RF Model |
|--------|-----------|----------|
| Total Latency | **2 ms** | — |
| RAM Usage | **0.2 KB** | — |
| Flash Usage | **34.7 KB** | — |

### C. Confusion Matrices

| ANN | Random Forest |
|---|---|
| <img src="https://github.com/user-attachments/assets/014a1879-1b5f-4f2e-ac02-f0a412282ac2" width="350"> | <img src="https://github.com/user-attachments/assets/2f41fc5f-e1b2-461d-95f4-9d60bd418ead" width="350"> |

---

## III. Artificial Neural Network (ANN) Architecture

The anomaly detection is performed using a **Multi-Layer Perceptron (MLP)** optimized for real-time embedded inference.

### A. Input Layer

| Component | Description |
|----------|-------------|
| Data Source | `ready_data.csv` |
| Input Size | ~11–13 statistical and temporal signal features |
| Purpose | Encode signal behavior patterns |

### B. Hidden Layers

| Layer | Neurons | Activation |
|------|---------|------------|
| Hidden Layer 1 | 128 | ReLU |
| Hidden Layer 2 | 64 | ReLU |
| Hidden Layer 3 | 32 | ReLU |

### C. Output Layer

| Output | Description |
|--------|-------------|
| 1 neuron | Sigmoid → Probability of anomaly |

| Output Value | Interpretation |
|-------------|----------------|
| ≈ 0 | Normal behavior |
| ≈ 1 | Anomaly detected |

### D. Key Deployment Metrics

| Metric | Value |
|-------|-------|
| Classification Accuracy | 95.65% |
| F1 Score | 89.1% |
| Latency | ~2 ms |
| RAM Usage | ~0.2 KB |
| Flash Size | ~34.7 KB |

Neural Network Diagram:
<img width="354" height="1105" src="https://github.com/user-attachments/assets/be273db6-7474-4e1a-8579-1a93560f8be3" />

---
