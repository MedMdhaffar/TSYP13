# 🚀 Model Deployment on STM32 (STM32Cube.AI) + Edge Impulse Project Resources

This repository provides everything needed to train, export, and deploy the **Anomaly Detection + Correction** neural network onto the **STM32F429** microcontroller.

The project was developed using **Edge Impulse**, exported as an **STM32Cube.AI pack**, and deployed via **STM32CubeIDE**.

---

## 📂 Repository Structure

```bash
.
├── data_acquisition/ # Scripts to upload ADCS telemetry to Edge Impulse
├── processing_block/ # Feature extraction pipeline used inside Edge Impulse
├── learning_block/ # Custom NN architecture & training configs from Edge Impulse
├── satellite_telemetry_anomaly_dete.1.0.3.pack # Deployment package for STM32CubeMX / Cube.AI
└── STM32f429/ # STM32CubeIDE firmware project that runs the model onboard
```


### Folder Purpose Summary

| Folder / File | Purpose |
|---------------|---------|
| `data_acquisition/` | Raw telemetry upload to Edge Impulse Studio. |
| `processing_block/` | Feature extraction pipeline configuration. |
| `learning_block/` | Neural network architecture and training config. |
| `satellite_telemetry_anomaly_dete.1.0.3.pack` | Pre-compiled Edge Impulse deployment model for STM32. |
| `STM32f429/` | Firmware + inference code (ready to compile and run). |

---

## 🧠 How the Model Was Built

1. Telemetry was collected and uploaded using **data_acquisition** scripts.
2. Feature extraction was designed using **processing_block**.
3. Neural network classifier was configured in **learning_block**.
4. Final model exported as:


satellite_telemetry_anomaly_dete.1.0.3.pack

which integrates directly with **STM32CubeMX + STM32Cube.AI**.

### Learn How to Import the `.pack` File into STM32CubeIDE

Follow the official Edge Impulse guide:  
https://docs.edgeimpulse.com/hardware/deployments/run-cubemx

---

## 🛰 Deploying and Running the Model on STM32F429

### Requirements

| Tool | Purpose | Link |
|------|---------|------|
| STM32CubeIDE | Build + Flash firmware | https://www.st.com/en/development-tools/stm32cubeide.html |
| PuTTY | Serial terminal | https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html |
| 7Zip | Proper extraction of the project | https://www.7-zip.org |

Download and extract the STM32 project via **7Zip**:

<p align="center">
<img width="442" height="370" src="https://github.com/user-attachments/assets/fe3d5d39-351a-429a-b7b5-d6a5c71a6df7" />
</p>

---

## Opening the Project in STM32CubeIDE

1. Connect the **STM32F429** board.
2. Open:

File → Open Projects from File System

3. Select one of the STM32 project directories:

STM32f429/edge impulse/supmohamed

4. Click **Finish**.

---

## Build and Debug

### Build Firmware

Project → Build All


<p align="center">
  <img width="537" height="42" src="https://github.com/user-attachments/assets/12cec1f7-e8fe-4128-abca-ccedb6fe243f" />
</p>

Successful build looks like:

<p align="center">
  <img width="779" height="207" src="https://github.com/user-attachments/assets/6309f690-6cd3-4350-9356-a5c4927c0e6c" />
</p>

If a popup appears → **Click OK**.

### Start Debug Session

<p align="center">
  <img width="312" height="51" src="https://github.com/user-attachments/assets/68ed1b63-6d35-47c5-a903-b353d9a4eb28" />
</p>

You should now see debugging mode:

<p align="center">
  <img width="1918" height="1196" src="https://github.com/user-attachments/assets/270aff38-cd70-4b2d-a05f-e9a5ae79c6de" />
</p>

---

## Viewing Output (PuTTY Serial Monitor)

1. Open **Device Manager** → Find STM32 COM Port
2. Open `PuTTY` → `Serial`
3. Configure:

| Setting | Value |
|--------|-------|
| Serial Line | Your detected COM port |
| Baud Rate | 115200 |

<p align="center">
  <img width="211" height="39" src="https://github.com/user-attachments/assets/72697f17-985e-47e2-ace4-1aa7f4efeab6" />
</p>

4. In STM32CubeIDE → **Resume** execution:

<p align="center">
  <img width="32" height="22" src="https://github.com/user-attachments/assets/8e83ab1e-3f8d-4de4-b221-6c9b4ae2e7c8" />
</p>

Output appears:

<p align="center">
  <img width="655" height="701" src="https://github.com/user-attachments/assets/4fb3cbf1-8c09-4d83-944f-b8b5ad2a0ff7" />
</p>

---

## Editing Input Telemetry

Modify values inside:

STM32f429/.../Core/Src/main.c


Change:
```c
float rawData[] = { ... };
uint32_t timestamps[] = { ... };


```
Rebuild → Debug → View output again.
