# Model Deployment on STM32 (STM32Cube.AI)

This guide explains how to deploy and run the **Anomaly Detection + Correction Neural Networks** on the **STM32F429** microcontroller using **STM32Cube.AI**.

---

## Table of Contents
1. Requirements
2. Opening the Project in STM32CubeIDE
3. Build and Debug
4. Viewing Output via Serial Terminal
5. Modifying Input Data
6. Project Structure

---

## Requirements

| Tool | Purpose | Link |
|------|---------|------|
| STM32CubeIDE | Build + Flash firmware | https://www.st.com/en/development-tools/stm32cubeide.html |
| PuTTY | Serial terminal monitor | https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html |
| 7Zip | Extract the project correctly | https://www.7-zip.org |

Download the STM32 project as a ZIP file and extract it using **7Zip**:

<p align="center">
  <img width="442" height="370" src="https://github.com/user-attachments/assets/fe3d5d39-351a-429a-b7b5-d6a5c71a6df7" />
</p>

---

## Opening the Project in STM32CubeIDE

1. Connect the **STM32F429** board to your PC via USB.
2. Open **STM32CubeIDE** → `File` → **Open Projects from File System…**

<p align="center">
  <img width="864" height="156" src="https://github.com/user-attachments/assets/40aa8795-9a06-4174-adb7-ffcdca5e3ec5" />
</p>

3. Select one of the following paths:

