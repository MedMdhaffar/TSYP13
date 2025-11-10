## 🛠️ Sensor Correction Models (9-Model Suite)

This folder contains **9 machine learning models** (random forest models ) , each trained to detect and correct abnormal sensor readings from the CubeSat ADCS telemetry.

### 📂 Folder Structure
```bash
model1.ipynb
model2.ipynb
model3.ipynb
model4.ipynb
model5.ipynb
model6.ipynb
model7.ipynb
model8.ipynb
model9.ipynb
telemetry.csv
```

🔍 Purpose

Each notebook (modelX.ipynb) corresponds to one specific onboard sensor.
The goal is to predict the corrected (normal) value when the real-time measurement is noisy, faulty, or deviates from expected spacecraft dynamics.

File	Description
model1.ipynb → model9.ipynb	Individual correction models (one per sensor)
telemetry.csv	Training dataset containing recorded CubeSat sensor readings

During training, each model learns:

Normal operational behavior of its respective sensor

How to reconstruct expected values during anomalies

✅ model test result (One Model Result)

<p align="center"> <img width="454" height="97" src="https://github.com/user-attachments/assets/8618a10a-ddee-44ef-9a51-b9861af2cf88" /> </p>
