# 🔋 Smart Battery Cooling System Using AI & Peltier Module

This project uses **Machine Learning** to detect potential battery overheating and trigger a **Peltier cooling system** via NodeMCU.

---

## 📦 Contents

- `generate_dataset.py` – Creates demo-friendly fake sensor data
- `train_model.py` – Trains ML model (Random Forest)
- `battery_model.pkl` – Saved ML model
- `api_server.py` – Flask API to serve the model
- `battery_ui.py` – Streamlit interface for demo/testing
- `nodemcu_test.ino` – NodeMCU (ESP8266) test Arduino code
- `battery_data.csv` – Generated dataset
- `requirements.txt` – Python dependencies

---

## 🧠 How the ML Works

The model predicts overheating (`1`) or normal (`0`) based on:
- Temperature
- Voltage
- Current
- Ambient Temperature
- Battery Charge %

> For demo, the model uses a **low threshold** (28°C) so you can test easily even without real overheating.

---

## ⚙️ Setup Instructions (Python Side)

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/SmartBatteryCoolingSystem.git
cd SmartBatteryCoolingSystem
```
#Install Required Python Packages
```bash
pip install -r requirements.txt
```
#Generate Data & Train the Model
```bash
python generate_dataset.py      # Creates battery_data.csv with labels
python train_model.py           # Trains and saves battery_model.pkl

```
#Run Flask API (Required by NodeMCU)
```bash
python api_server.py
```
#Test Using Streamlit UI (Optional Demo)
```bash
streamlit run battery_ui.py
```
