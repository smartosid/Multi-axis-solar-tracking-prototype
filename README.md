# Multi-axis-solar-tracking-prototype

# ☀️ Multi-Axis Solar Tracking System using Arduino

This project is a **dual-axis solar tracking system** that automatically adjusts the position of a solar panel to face the sun directly throughout the day using **light sensors and servo motors**. It increases the efficiency of solar energy capture by maximizing sunlight exposure on both horizontal and vertical axes.

---

## 🔧 Hardware Components

| Component           | Quantity | Description                                 |
|--------------------|----------|---------------------------------------------|
| Arduino Uno/Nano    | 1        | Microcontroller for controlling the system  |
| Servo Motor (SG90/MG995) | 2        | For vertical and horizontal movement       |
| LDR (Light Dependent Resistor) | 4        | For detecting sunlight direction          |
| Resistors (10kΩ)    | 4        | For voltage divider circuits with LDRs     |
| Solar Panel         | 1        | Optional, for actual energy harvesting      |
| Breadboard & Wires  | -        | For circuit connections                    |
| Mounting Frame      | 1        | For holding the panel and servos           |

---

## 🧠 Features

- 🌞 **Dual-Axis Tracking**: Tracks both azimuth (left/right) and elevation (up/down)
- 🔍 **Light Intensity Sensing**: Uses 4 LDRs placed in a cross pattern
- 🧭 **Servo Control**: Adjusts panel orientation based on LDR values
- ⚡ **Improved Efficiency**: More solar energy captured than fixed panels

---

## ⚙️ Working Principle

- The LDR sensors detect sunlight intensity from four directions: top, bottom, left, right.
- The Arduino calculates the difference between opposite LDRs.
- Based on the difference, it rotates the vertical and horizontal servos to align the panel perpendicular to sunlight.
- When all LDRs receive almost equal light, the panel is considered aligned.

---

## 🧪 Software Setup

### 1. Upload the Code

- Open the `.ino` file in the Arduino IDE.
- Connect your Arduino board via USB.
- Select the correct board and port.
- Upload the code.

### 2. Circuit Diagram

> Connect LDRs in voltage divider configuration with 10kΩ resistors.  
> Attach each LDR output to analog pins A0–A3.  
> Connect servos to digital PWM pins (e.g., D9 and D10).

---


