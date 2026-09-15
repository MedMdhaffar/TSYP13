# 🛰️ AI-Driven Predictive Maintenance for OPS-SAT ADCS

## Autonomous ADCS Monitoring System for 3U CubeSats

### Prototype

<p align="center">
  <img
    src="https://github.com/user-attachments/assets/53585b5f-ae8a-42af-b20a-648b7dd295e2"
    width="500"
    alt="image"
  />
</p>

### Project Overview

This repository features the development of a resilient, **AI-driven electronics subsystem** for the European Space Agency's (ESA) **OPS-SAT CubeSat**. The project's core mission is to create an **Autonomous Attitude Determination and Control System (ADCS) Monitoring System** that employs predictive maintenance algorithms to autonomously detect and correct anomalies while operating in space.

By running complex diagnostics directly on-board, the system significantly enhances mission resilience and reduces reliance on ground control, directly mitigating the high risk of failure often associated with CubeSat ADCS subsystems.

<p align="center">
  <img src="https://github.com/user-attachments/assets/a37d5b38-a686-4b0a-a191-43fa7d2d493b" width="100%">
</p>


## ✨ System Architecture and Key Features

The solution leverages a dual-AI approach optimized for low-power edge computing.

| Feature | Description |
| :--- | :--- |
| **Autonomous Anomaly Detection** | An **Artificial Neural Network (ANN)** model analyzes real-time sensor data to flag faults and deviations from normal operating conditions. |
| **Predictive Signal Correction** | Nine specialized **Random Forest models** are utilized—one for each monitored ADCS channel—to autonomously calculate and apply corrections to abnormal signals. |
| **Edge AI Optimization** | Models are deployed onto the **STM32F429** microcontroller for highly efficient, low-latency inference, respecting crucial **CubeSat constraints** (power, volume, radiation tolerance). |
| **Detection Performance** | The core ANN model validation yielded high results on the testing set: **95.65% Accuracy** and an **89.1% F1 Score**. |

<img width="3078" height="3234" alt="Design sans titre" src="https://github.com/user-attachments/assets/23293640-3e94-43c9-8125-23f23cf26113" />

### Electrical schema :
<img width="1328" height="933" alt="image" src="https://github.com/user-attachments/assets/a676e3aa-4515-4038-8c16-7d64628d5c7f" />

---

## 📂 Repository Structure
The project code and resources are logically separated into three major development areas: Machine Learning (ML), Data Processing, and Embedded Implementation.
```bash
├── ML_models(detection)    # Anomaly Detection (ANN) Model Notebooks and Training Data
├── ML_models(correction)   # Random Forest Correction Model Notebooks (Model1 to Model9)
├── edge_impulse            # Data Acquisition Scripts and Edge Impulse Project Configurations
├── STM32f429               # Final Embedded Firmware (High-Accuracy CubeAI & Edge Impulse Deployments)
├── schemaelectrique        # Electrical Schematics and Hardware Interface Design Files
├── .gitignore              # Specifies files and directories ignored by Git
├── LICENCE                 # Project's Proprietary License File
└── README.md               # Project overview, features, and setup instructions
```

---

## 🧠 I. Machine Learning Models

The ML subsystem is divided into **anomaly detection** and **predictive correction**, covering **9 ADCS sensor channels**.

### A. **Anomaly Detection **  
**Directory:** `ML_models(detection)`

Detects anomalies in real-time based on magnetometer and sun sensor data.

**Monitored Sensor Channels:**  
- Magnetometer: `X`, `Y`, `Z`  
- Sun Sensor / Photodiodes: `PD1–PD6`

**Performance (Testing Set)(ANN model):**
| Metric | Value |
|--------|-------|
| Accuracy | **95.65%** |
| F1 Score | **89.10%** |
| AUC | **97.63%** |

**Embedded Deployment (Cortex-M4F)(ANN model):**
| Parameter | Value |
|----------|-------|
| Latency | **~2 ms** |
| RAM Usage | **~0.2 KB** |
| Flash Usage | **~34.7 KB** |

---

### B. **Predictive Correction (Random Forest Models)**  
**Directory:** `ML_models(correction)`

After the ANN detects an anomaly, **9 dedicated Random Forest models** (one per sensor channel) predict corrected values, enabling **autonomous recovery without ground control**.

---

## ⚙️ II. Embedded Firmware (STM32F429)

**Directory:** `STM32f429`  
Implements the ML models on the **STM32F429 Discovery Kit (ARM Cortex-M4F)**.

### Deployment Modes:
| Mode | Description | Purpose |
|------|-------------|---------|
| **CubeAI (Optimized)** | Converts ANN to C for real-time inference | **Flight-ready implementation** |
| **Edge Impulse** | Rapid experimentation (lower accuracy) | Comparison + development |

### Hardware Interfaces:
- **STM32F429 MCU** → On-board processing + inference  
- **MPU-9250 IMU** → 9-axis attitude sensing  
- **NanoCom AX100** → Communication subsystem simulation

Designed for CubeSat constraints: low power, radiation tolerance, thermal stability, compact integration.

---

## 🛰️ III. Data Acquisition & Feature Engineering

**Directory:** `edge_impulse`

Contains:
- Scripts for uploading ADCS telemetry data
- Feature extraction / DSP processing pipelines
- Edge Impulse neural network training configuration

Used for:
- Data preparation
- Prototype model experimentation
- Performance comparison with CubeAI deployment

---



## ⚙️ Deployment and Development Tools

This project utilizes the following key tools and platforms:

* **Microcontroller:** STM32F429ZIT6 (Arm® Cortex®-M4)
* **Embedded IDE:** STM32CubeIDE
* **ML Frameworks:** TensorFlow/Keras, Scikit-learn, STM32Cube.AI, Edge Impulse

## 🚀 Getting Started

### Clone the Repository

download the code as a ZIP file (required)
