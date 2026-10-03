# ESP32 Web Server — On/Off Inbuilt LED Control

### Task 1 — Embedded HTTP Web Server

> A foundational project implementing an embedded HTTP web server on an ESP32 to control the onboard LED via local Wi-Fi.

---

## 📌 Overview
This task demonstrates the core capabilities of the ESP32 to act as a standalone web server. By connecting to a local Wi-Fi network and listening on Port 80, the ESP32 serves a basic web interface that allows users to toggle its onboard LED (GPIO 2) by triggering specific HTTP endpoints.

## 🎯 Objectives
- Connect the ESP32 to a local Wi-Fi network.
- Establish an HTTP web server on Port 80.
- Configure GPIO 2 to drive the onboard LED.
- Define HTTP endpoints `/on` and `/off` to trigger hardware actions.

## 🧠 Concepts Covered
- Embedded Web Servers
- HTTP Requests (GET)
- Wi-Fi Station Mode on ESP32
- GPIO Manipulation
- Client-Server Architecture

## 🏗️ System Architecture
1. **Client**: A web browser (Smartphone/PC) sends HTTP requests to the ESP32's local IP address.
2. **Server (ESP32)**: Processes incoming HTTP requests and updates the hardware state.
3. **Actuator**: The onboard LED (GPIO 2) turns ON or OFF based on the requested endpoint.

## 🔧 Hardware
- ESP32 Development Board
- Onboard LED (connected to GPIO 2)

## 💻 Software
- Arduino IDE (C++)
- `WiFi.h` library
- `WebServer.h` library

## ⚙️ Implementation
The ESP32 is programmed in C++ using the Arduino IDE. It uses placeholder credentials for Wi-Fi authentication. The `WebServer` library handles incoming client connections on Port 80, parsing requests and updating the state of `GPIO 2`. 
- When `http://<IP>/on` is hit, `digitalWrite(2, HIGH)` is called.
- When `http://<IP>/off` is hit, `digitalWrite(2, LOW)` is called.

## 🧪 Testing
The system was tested by observing the ESP32 Serial Monitor to verify the acquired IP address. Upon entering the IP address in a browser and navigating to the `/on` and `/off` routes, the onboard LED reliably toggled states with minimal latency.

## 🛠️ Challenges & Fixes
- **Wi-Fi Connectivity**: Intermittent connection drops were resolved by ensuring the board was within range of a stable 2.4GHz network.
- **State Feedback**: Initially, the UI didn't show the LED state. This was fixed by returning dynamic HTML from the ESP32 based on the current GPIO state.

## 📚 Learning Outcomes
- Gained hands-on experience configuring ESP32 Wi-Fi credentials.
- Understood the mechanics of HTTP routing on microcontrollers.
- Successfully bridged software web interactions with physical hardware responses.

## 💭 Reflection
This task served as an excellent entry point into IoT, highlighting how easily physical devices can be exposed to a local network. It paved the way for more complex, cloud-based architectures.

## 🔗 Project Information
- **Developer**: Harish Kumaran
- **Course**: ProtoSem
- **Module**: Week 7 IoT Lab

## 🏁 Conclusion
The ESP32 Web Server was successfully implemented, providing reliable local control over hardware. This foundational step is critical before moving to more advanced MQTT cloud integrations.
