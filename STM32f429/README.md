# 🚀 On-Board AI for ADCS Anomaly Detection  
**Model Deployment on STM32 (STM32Cube.AI)and (Edge impulse)**

This guide explains how to deploy and run the **Anomaly Detection + Correction Neural Networks** on the **STM32F429** microcontroller using **STM32Cube.AI** and **Edge impulse**.  
The model performs **real-time inference on-board** to detect anomalies in ADCS (Attitude Determination and Control System) telemetry, enabling on-orbit autonomy and safe satellite operation.

---

## 📌 Table of Contents
1. Requirements  
2. Opening the Project in STM32CubeIDE  
3. Build and Debug  
4. Viewing Output via Serial Terminal  
5. Modifying Input Data  
6. Project Structure  

---

## ✅ Requirements

| Tool | Purpose | Link |
|------|---------|------|
| **STM32CubeIDE** | Build + Flash firmware | https://www.st.com/en/development-tools/stm32cubeide.html |
| **PuTTY** | Serial terminal monitor | https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html |
| **7Zip** | Proper project extraction | https://www.7-zip.org |

Extract the STM32 project using **7Zip** to avoid folder structure errors:

<p align="center">
  <img width="442" height="370" src="https://github.com/user-attachments/assets/fe3d5d39-351a-429a-b7b5-d6a5c71a6df7" />
</p>

---

## 🧰 Opening the Project in STM32CubeIDE

1. Connect the **STM32F429** board to your PC via USB.
2. Open:

STM32CubeIDE → File → Open Projects from File System…


<p align="center">
  <img width="864" height="156" src="https://github.com/user-attachments/assets/40aa8795-9a06-4174-adb7-ffcdca5e3ec5" />
</p>

3. Select this folder:

TSYP13-main/STM32f429/Cube_AI/satellite_anomaly_detection_model  or  TSYP13-main/STM32f429/edge impulse/supmohamed


Click **Finish**.

---

## ⚙️ Build and Debug

### Build

Project → Build All


<p align="center">
  <img width="537" height="42" src="https://github.com/user-attachments/assets/12cec1f7-e8fe-4128-abca-ccedb6fe243f" />
</p>

Expected successful build:

<p align="center">
  <img width="779" height="207" src="https://github.com/user-attachments/assets/6309f690-6cd3-4350-9356-a5c4927c0e6c" />
</p>

### Debug
Click the **Debug** button:

<p align="center">
  <img width="312" height="51" src="https://github.com/user-attachments/assets/68ed1b63-6d35-47c5-a903-b353d9a4eb28" />
</p>

You should now be in debugging mode:

<p align="center">
  <img width="1918" height="1196" src="https://github.com/user-attachments/assets/270aff38-cd70-4b2d-a05f-e9a5ae79c6de" />
</p>

---

## 🛰 Viewing Real-Time Output via Serial Terminal

1. Open **Device Manager** → find the **COM port**:

<p align="center">
  <img width="773" height="563" src="https://github.com/user-attachments/assets/983d6b1f-016e-4e7f-9178-e7deb976d8a1" />
</p>

2. Open **PuTTY** → Select "Serial".

| Setting | Value |
|--------|-------|
| Serial Line | COMX (your board port) |
| Speed | 115200 |

<p align="center">
  <img width="211" height="39" src="https://github.com/user-attachments/assets/72697f17-985e-47e2-ace4-1aa7f4efeab6" />
</p>

Click **Open**.

3. In CubeIDE, click **Resume**:

<p align="center">
  <img width="32" height="22" src="https://github.com/user-attachments/assets/8e83ab1e-3f8d-4de4-b221-6c9b4ae2e7c8" />
</p>

Expected terminal output:

<p align="center">
  <img width="655" height="701" src="https://github.com/user-attachments/assets/4fb3cbf1-8c09-4d83-944f-b8b5ad2a0ff7" />
</p>

---

## ✏️ Modifying the Input Data

Edit the input arrays in:

Core/Src/main.c ( or main.cpp in edge impulse project )


```c
float rawData[] = { ... };
uint32_t timestamps[] = { ... };
```

or 
```cpp
static const float features[] ={ ... };
```

Optional source:

segments.csv

Rebuild → Debug → View output in PuTTY.

📂 Project Structure
```bash
Cube_AI/satellite_anomaly_detection_model
├── Core
├── Drivers
├── Middlewares
├── X-CUBE-AI
├── .ai
├── .cproject
├── .mxproject
├── .project
├── STM32F429ZITX_FLASH.ld
├── STM32F429ZITX_RAM.ld
└── tsyp.ioc
```
