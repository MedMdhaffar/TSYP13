## I- Model Deployment on STM32 (CubeAI)

The machine learning models (detection+correction) are deployed using **STM32Cube.AI**, optimized for embedded execution on the STM32F429 microcontroller.

### A. Requirements

1. **Install STM32CubeIDE**
   
   https://www.st.com/en/development-tools/stm32cubeide.html

3. **Install Putty**
   
   https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html

5. **Install 7Zip**
   
   https://www.7-zip.org

7. **Download / Open the Project**
   <img width="442" height="370" alt="image" src="https://github.com/user-attachments/assets/fe3d5d39-351a-429a-b7b5-d6a5c71a6df7" />

   
   download it as a zip file and then extract it as a 7Zip ( required )

8. **plug in the board via a USB port to your PC**

9. **Open STM32CubeIDE

   Go to tabs
   <img width="616" height="42" alt="image" src="https://github.com/user-attachments/assets/f7cbcaa1-9934-4dc9-a476-9a0900b729e3" />
   <img width="341" height="73" alt="image" src="https://github.com/user-attachments/assets/aeb01947-7f6b-4add-93bf-d6c29fd42ed1" />

   head to File / Open Projects from File System..

   <img width="864" height="156" alt="image" src="https://github.com/user-attachments/assets/40aa8795-9a06-4174-adb7-ffcdca5e3ec5" />

   head to Directory / Select the path to one of the two project either : \TSYP13-main\STM32f429\Cube_AI\satellite_anomaly_detection_model or : \TSYP13-main\STM32f429\edge impulse\supmohamed
   Click on Finish
   
   press on tab (project) then Build all then
   

   <img width="537" height="42" alt="image" src="https://github.com/user-attachments/assets/12cec1f7-e8fe-4128-abca-ccedb6fe243f" />
   <img width="253" height="79" alt="image" src="https://github.com/user-attachments/assets/a5773f7a-f02b-4f98-b496-a3c06254a825" />
   if everything is ok the following logs should be diplayed
   
   <img width="779" height="207" alt="image" src="https://github.com/user-attachments/assets/6309f690-6cd3-4350-9356-a5c4927c0e6c" />

   remark :

   If this shows always click on (OK)
   <img width="495" height="153" alt="image" src="https://github.com/user-attachments/assets/75be96bf-93a8-471e-90ef-b0cc98e33b02" />

   then click on debug
   <img width="312" height="51" alt="image" src="https://github.com/user-attachments/assets/68ed1b63-6d35-47c5-a903-b353d9a4eb28" />


   after that you should have this :
   <img width="1918" height="1196" alt="image" src="https://github.com/user-attachments/assets/270aff38-cd70-4b2d-a05f-e9a5ae79c6de" />

   After press win + X :
   choose "devive manager"

   then  go to Ports (COM & LPT)
   you should see this :
   <img width="773" height="563" alt="image" src="https://github.com/user-attachments/assets/983d6b1f-016e-4e7f-9178-e7deb976d8a1" />
   then identify the serial line the STM is connected to 
   then open "putty"
   click on serial :
   <img width="164" height="43" alt="image" src="https://github.com/user-attachments/assets/e32604f5-18ba-4b8e-b6c6-a41753a7967f" />
   put the serial line you card is connect to :

   <img width="211" height="39" alt="image" src="https://github.com/user-attachments/assets/72697f17-985e-47e2-ace4-1aa7f4efeab6" />
   then change the speed to "115200"
   <img width="75" height="43" alt="image" src="https://github.com/user-attachments/assets/258f5f61-2dad-47b1-aecc-1236a406be13" />
   finally click on open :
   a terminal shoould  appear to you :
   <img width="656" height="414" alt="image" src="https://github.com/user-attachments/assets/ee4f722f-4825-4c86-9a6c-ec54e401bbca" />

   go back to your stm32CubeIDE :
   then click on resume :
   <img width="32" height="22" alt="image" src="https://github.com/user-attachments/assets/8e83ab1e-3f8d-4de4-b221-6c9b4ae2e7c8" />


   then go back to putty you should see the output coming from the electric card :
   <img width="655" height="701" alt="image" src="https://github.com/user-attachments/assets/4fb3cbf1-8c09-4d83-944f-b8b5ad2a0ff7" />

   to change the output values you should change the input :
   go to Core/Src/main.c 
   then go to :
   float rawData array and change the values
   and the values of timestamps array 
   remark :
   you can get the values from the segments.csv or you can put any values you want
   and the repeat the proceess to see the output
   
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
