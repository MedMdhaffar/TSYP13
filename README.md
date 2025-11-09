# 🛰️ AI-Driven Predictive Maintenance for OPS-SAT ADCS

## Autonomous ADCS Monitoring System for 3U CubeSats

### Project Overview

This repository features the development of a resilient, **AI-driven electronics subsystem** for the European Space Agency's (ESA) **OPS-SAT CubeSat**. The project's core mission is to create an **Autonomous Attitude Determination and Control System (ADCS) Monitoring System** that employs predictive maintenance algorithms to autonomously detect and correct anomalies while operating in space.

By running complex diagnostics directly on-board, the system significantly enhances mission resilience and reduces reliance on ground control, directly mitigating the high risk of failure often associated with CubeSat ADCS subsystems.

---

## ✨ System Architecture and Key Features

The solution leverages a dual-AI approach optimized for low-power edge computing.

| Feature | Description |
| :--- | :--- |
| **Autonomous Anomaly Detection** | An **Artificial Neural Network (ANN)** model analyzes real-time sensor data to flag faults and deviations from normal operating conditions. |
| **Predictive Signal Correction** | Nine specialized **Random Forest models** are utilized—one for each monitored ADCS channel—to autonomously calculate and apply corrections to abnormal signals. |
| **Edge AI Optimization** | Models are deployed onto the **STM32F429** microcontroller for highly efficient, low-latency inference, respecting crucial **CubeSat constraints** (power, volume, radiation tolerance). |
| **Detection Performance** | The core ANN model validation yielded high results on the testing set: **95.65% Accuracy** and an **89.1% F1 Score**. |

---

## 📂 Repository Structure

The project code and resources are logically separated into three major development areas: Machine Learning (ML), Data Processing, and Embedded Implementation.

| Directory | Purpose and Content |
| :--- | :--- |
| `ML_models(detection)` | Contains the notebooks, training data, and source code used for developing the primary **Anomaly Detection (ANN) model** and generating the final dataset. |
| `ML_models(correction)` | Dedicated space for the notebooks (e.g., `model1.ipynb` to `model9.ipynb`) used to train and validate the **nine Random Forest correction models**. |
| `edge_impulse/` | Includes scripts for **data acquisition** (used for uploading data to the Edge Impulse platform), the **processing block** for feature extraction, and the **learning block** used to implement a lower-accuracy NN model within the platform. |
| `STM32f429/` | Houses the **final embedded firmware** for the STM32F429 Discovery Kit. This includes two distinct deployments: one using the **Edge Impulse** framework and a highly optimized, high-accuracy deployment using the **CubeAI framework** within STM32CubeIDE. |
| `schemaelectrique` | Stores project files related to the **electrical schematics** and hardware interface design for the integrated ADCS and AI subsystem. |

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
