## Model Deployment on STM32 (CubeAI)

The final anomaly detection model is deployed using **STM32Cube.AI**, optimized for embedded execution on the STM32F429 microcontroller.

### A. Requirements

1. **Install STM32CubeIDE**  
   https://www.st.com/en/development-tools/stm32cubeide.html

3. **Install Putty**
   https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html

4. **Install 7Zip**
   https://www.7-zip.org

5. **Download / Open the Project**
   download it as a zip file and then extract it as a 7Zip ( required )

6. **Open STM32CubeIDE
   head to File / Open Projects from File System..
   head to Directory / Select the path to one of the two project either : \TSYP13-main\STM32f429\Cube_AI\satellite_anomaly_detection_model or : \TSYP13-main\STM32f429\edge impulse\supmohamed
   Click on Finish
   press on tab (project) then Build all then
   If this shows click on (OK)
   
   <img width="495" height="153" alt="image" src="https://github.com/user-attachments/assets/75be96bf-93a8-471e-90ef-b0cc98e33b02" />

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
