# 🛰️ AI-Driven Predictive Maintenance for OPS-SAT ADCS

## Autonomous ADCS Monitoring System for 3U CubeSats

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

## ⚙️ Deployment and Development Tools

This project utilizes the following key tools and platforms:

* **Microcontroller:** STM32F429ZIT6 (Arm® Cortex®-M4)
* **Embedded IDE:** STM32CubeIDE
* **ML Frameworks:** TensorFlow/Keras, Scikit-learn, STM32Cube.AI, Edge Impulse

## 🚀 Getting Started

### Prerequisites

* Python 3.x
* Required ML libraries (e.g., NumPy, Pandas, Scikit-learn, TensorFlow/Keras)
* STM32CubeIDE (for embedded code compilation and flashing)
* Git

### ML Model Training

1.  Navigate to the ML directories:
    ```bash
    cd ML_models/OPS-SAT-NN/
    ```
2.  Run the notebooks (`dataset_generator.ipynb`) to process and prepare training data.
3.  Train and refine the ANN detection model.
4.  Navigate to the correction model folder to train the Random Forest models:
    ```bash
    cd correction_model/
    ```
5.  Run `model1.ipynb` through `model9.ipynb` to train the individual correction models.

### Embedded Deployment (Edge AI)

1.  Export the trained models (e.g., TFLite or C-code format).
2.  Open the project within the `STM32f429/Cube_AI/satellite_anomaly_detection_model/` directory using **STM32CubeIDE**.
3.  Compile and flash the code onto the **STM32F429 Discovery Kit** for real-time validation.

## ⚙️ Core Technology

| Component | Role |
| :--- | :--- |
| **Microcontroller** | STM32F429ZIT6 (Arm® Cortex®-M4) |
| **Detection AI** | Artificial Neural Network (ANN) |
| **Correction AI** | 9 Random Forest Classifiers |
| **Sensors Monitored** | Magnetometer (3-axis) and Photodiodes (6 channels) |

## 📄 License

This project is developed for the IEEE AESS Challenge (TSYP 13). All associated code and documentation rights are reserved by the authors and challenge rules.
