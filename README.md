9# 🛰️ Autonomous ADCS Monitoring System for 3U
CubeSats(OPS-SAT) Using AI-Driven Predictive
Maintenance

## Project Overview

This repository documents the development of an **AI-driven electronics subsystem** for the European Space Agency's (ESA) **OPS-SAT CubeSat**. The core goal is to implement an **Autonomous Attitude Determination and Control System (ADCS) Monitoring System** that utilizes predictive maintenance to autonomously detect and correct anomalies in space.

The system is designed to operate independently of ground control, enhancing mission resilience and mitigating the high risk of failure often associated with CubeSat ADCS issues.

## 🌟 Key Features

* **Autonomous Anomaly Detection:** An **Artificial Neural Network (ANN)** model detects faults in real-time sensor data from the ADCS.
* **Predictive Correction:** Nine separate **Random Forest models** are used to autonomously correct abnormal signals for each monitored ADCS channel.
* **Edge AI Implementation:** The ML models are deployed onto a resource-constrained platform, specifically targeting the **STM32F429** microcontroller for efficient, low-latency inference.
* **Hardware Focus:** The electronic subsystem respects critical CubeSat constraints (power, volume, radiation tolerance).
* **Performance:** The core ANN detection model achieved a testing accuracy of **95.65%** and an F1 score of **89.1%**.

## 💻 Repository Structure

The project is organized into three main development areas: Machine Learning (ML), Data Processing, and Embedded Implementation.

| Directory | Description |
| :--- | :--- |
| `ML_models(detection)` | Contains notebooks, data and code for the main **Anomaly Detection (ANN)** model training and dataset generation. |
| `ML_models(correction)` | Hosts the notebooks (e.g., `model1.ipynb` to `model9.ipynb`) for training the **nine Random Forest models** used for autonomous signal correction. |
| `edge_impulse/` | Contains data_aquisition used to upload data to edge impulse, processing block used for feature extraction and learning block used to implement the machine learning NN model in the platform. |
| `STM32f429/` | Contains the two **final embedded code** for the STM32F429 Discovery Kit, the first is deployed using edge impulse(low accuracy NN model) and the second is developped using CubeAI framework in STM32CubeIDE (high accuracy)and highly optimised. |
| `schemaelectrique` | Project files containing electrical schematics and hardware design related to the ADCS and AI subsystem. |

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
