## Model Deployment on STM32 (CubeAI)

The final anomaly detection model is deployed using **STM32Cube.AI**, optimized for embedded execution on the STM32F429 microcontroller.

### A. Requirements

1. **Install STM32CubeIDE**  
   https://www.st.com/en/development-tools/stm32cubeide.html

3. **Install Putty**
   https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html

2. **download / Open the Project**
   doawnload it as a zip file

### B. Project Structure
```bash
Cube_AI/satellite_anomaly_detection_model
├── .ai
├── .settings
├── Core
├── Drivers
├── Middlewares
├── X-CUBE-AI
├── .cproject
├── .mxproject
├── .project
├── LICENSE_X-CUBE-AI.txt
├── satellite_anomaly_detection_model.launch
├── STM32F429ZITX_FLASH.ld
├── STM32F429ZITX_RAM.ld
├── tsyp Debug.launch
└── tsyp.ioc
```
