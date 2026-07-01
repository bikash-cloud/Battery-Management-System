# 🔋 Adaptive Multi-Cell Battery Intelligence Engine

A production-grade Battery Intelligence Engine developed using **ESP32** in the **Wokwi Simulator**. The system continuously monitors a simulated **4-cell lithium-ion battery pack**, analyzes battery health, detects faults, and provides intelligent recommendations in real time.

---

## 📌 Project Overview

This project simulates a Battery Management System (BMS) capable of monitoring four battery cells simultaneously using analog inputs. It performs voltage measurement, battery analysis, health classification, fault detection, and displays all information through the Serial Monitor.

The project follows a **modular embedded software architecture**, making it scalable and easy to maintain.

---

## 🎯 Objectives

- Read 4 analog battery cell voltages.
- Calculate individual cell voltages.
- Calculate total pack voltage.
- Calculate average battery voltage.
- Identify the strongest and weakest battery cells.
- Calculate battery imbalance percentage.
- Classify battery health.
- Detect battery faults.
- Display battery State of Charge (SOC).
- Generate battery balancing recommendations.

---

# ⚙ Hardware Used

- ESP32 DevKit V4
- 4 × Potentiometers (Simulated Battery Cells)
- Wokwi Simulator

---

# 💻 Software Used

- Arduino IDE
- ESP32 Arduino Framework
- Wokwi Online Simulator

---

# 📂 Project Structure

```
Battery_Intelligence_Engine
│
├── sketch.ino
├── config.h
├── adc_reader.h
├── adc_reader.cpp
├── battery_engine.h
├── battery_engine.cpp
├── diagram.json
└── README.md
```

---

# 🚀 Features

## ✅ Real-Time Cell Monitoring

Reads four analog inputs continuously.

```
Cell 1 Voltage
Cell 2 Voltage
Cell 3 Voltage
Cell 4 Voltage
```

---

## ✅ Pack Voltage Calculation

Calculates

```
Pack Voltage
=
Cell1 + Cell2 + Cell3 + Cell4
```

---

## ✅ Average Cell Voltage

```
Average Voltage
=
Pack Voltage / Number of Cells
```

---

## ✅ Strongest Cell Detection

Automatically identifies the highest voltage cell.

Example

```
Strongest Cell : Cell 3
```

---

## ✅ Weakest Cell Detection

Automatically identifies the lowest voltage cell.

Example

```
Weakest Cell : Cell 2
```

---

## ✅ Cell Health Classification

Each battery cell is classified as:

- NORMAL
- UNDER VOLTAGE
- OVER VOLTAGE

Example

```
Cell 2 : UNDER VOLTAGE
Cell 3 : OVER VOLTAGE
```

---

## ✅ Battery Imbalance Detection

Calculates imbalance percentage between the strongest and weakest cells.

```
Imbalance (%)
=
(Max Voltage - Min Voltage)
----------------------------
Average Voltage
×100
```

---

## ✅ Battery Status Classification

The battery pack is classified into

- Healthy
- Minor Imbalance
- Critical Imbalance
- Pack Failure

---

## ✅ Battery State of Charge (SOC)

Displays battery percentage.

Example

```
Battery SOC : 72.5%
```

---

## ✅ Battery Level Indicator

ASCII Battery Bar

Example

```
[#######---] 70%
```

---

## ✅ Active Fault Detection

Automatically detects

- Under Voltage
- Over Voltage
- High Cell Imbalance
- Pack Failure

Example

```
Active Faults

• Cell 2 Under Voltage

• Cell 3 Over Voltage

• High Cell Imbalance

• Pack Failure
```

---

## ✅ Intelligent Recommendation Engine

Provides recommendations based on battery health.

Example

```
Recommendation

Inspect Weakest Cell

Perform Cell Balancing

Stop Operation
```

---

# 📊 Sample Output

```
================================================

BATTERY INTELLIGENCE ENGINE

================================================

Cell 1 : 1.54 V [NORMAL]

Cell 2 : 0.82 V [UNDER VOLTAGE]

Cell 3 : 3.10 V [OVER VOLTAGE]

Cell 4 : 1.72 V [NORMAL]

------------------------------------------------

Pack Voltage : 7.18 V

Average Voltage : 1.79 V

Battery SOC : 54 %

Battery Bar : [#####-----]

Strongest Cell : Cell 3

Weakest Cell : Cell 2

Imbalance : 42.8 %

Battery Status : Pack Failure

------------------------------------------------

Active Faults

• Cell 2 Under Voltage

• Cell 3 Over Voltage

• High Cell Imbalance

• Pack Failure

------------------------------------------------

Recommendation

Inspect Weakest Cell

Perform Cell Balancing

================================================
```

---

# 🏗 Modular Architecture

```
                sketch.ino
                     │
      ┌──────────────┼──────────────┐
      │                              │
adc_reader.cpp               battery_engine.cpp
      │                              │
      └──────────────┬──────────────┘
                     │
                 config.h
```

---

# ▶ How to Run

1. Open the Wokwi project.
2. Start the simulation.
3. Rotate the four potentiometers.
4. Observe the Serial Monitor.
5. Monitor battery health in real time.

---

# 🌐 Wokwi Simulation

Paste your Wokwi Share Link here:

```
https://wokwi.com/projects/PASTE_YOUR_PROJECT_LINK_HERE
```

---

# 📈 Future Improvements

- OLED Display
- LCD Dashboard
- Wi-Fi Monitoring
- MQTT Integration
- Firebase Cloud Logging
- SD Card Data Logging
- Battery Temperature Monitoring
- Charging/Discharging Detection
- Cell Balancing Algorithm
- Web Dashboard
- Mobile Application Integration

---

# 👨‍💻 Author

**BIKASH SWAIN**

B.Tech Electronics & Communication Engineering

Centurion University of Technology and Management

---

# 📜 License

This project is developed for educational and internship purposes.