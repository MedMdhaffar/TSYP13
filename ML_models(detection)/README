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

### A. **Artificial Neural Network (ANN)**
|               | **Predicted 0** (Normal) | **Predicted 1** (Anomaly) |
|---------------|-------------------------|---------------------------|
| **Actual 0** (Normal) | 412 (TN) | 4 (FP) |
| **Actual 1** (Anomaly) | 19 (FN) | 94 (TP) |

The ANN shows **very low false positive rate** (only 4 cases), while maintaining high anomaly detection sensitivity.

---

### B. **Random Forest (RF)**
|               | **Predicted 0** (Normal) | **Predicted 1** (Anomaly) |
|---------------|-------------------------|---------------------------|
| **Actual 0** (Normal) | 250 (TN) | 2 (FP) |
| **Actual 1** (Anomaly) | 15 (FN) | 52 (TP) |

The RF model produces fewer false positives, but **detects fewer anomalies**, making it less suitable for safety-critical ADCS monitoring.

---

## 🎯 Conclusion

The **Artificial Neural Network (ANN)** was selected as the final model due to:

- Higher **F1 Score** and **AUC**
- Better balance between detecting anomalies and avoiding false alarms
- **Significantly smaller inference footprint** when deployed on embedded hardware
- Real-time performance (**~2 ms latency**) on STM32F429 via **CubeAI**

This makes the ANN model both **accurate** and **deployment-efficient**, meeting the operational constraints of onboard satellite ADCS systems.

---
