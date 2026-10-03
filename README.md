# ESP32 Web Server HTML LED Control

### Task 1 — Embedded HTTP Web Server

---

## Task Overview
This project demonstrates the core capabilities of the ESP32 to act as a standalone embedded HTTP web server. By connecting to a local Wi-Fi network and listening on Port 80, the ESP32 serves a dynamic web interface that allows users to toggle its onboard LED by triggering specific HTTP endpoints.

## Problem / Purpose
The purpose of this task is to understand how physical microcontrollers can be exposed to a local network, bridging the gap between embedded systems and standard web protocols without relying on third-party cloud services.

## Objectives
- Connect the ESP32 to a local Wi-Fi network in Station Mode.
- Establish an HTTP web server listening on Port 80.
- Configure GPIO 2 to drive the onboard status LED.
- Define HTTP endpoints (`/on` and `/off`) to trigger hardware actions.

## Concepts Covered
- Embedded Web Servers
- HTTP GET Requests
- Wi-Fi Station Mode
- GPIO Manipulation
- Client-Server Architecture

## System Architecture

```text
[ Web Browser ]  --HTTP GET /on-->  [ ESP32 Web Server ]  -->  [ GPIO 2 HIGH ]
  (Client)                             (Port 80)                (Onboard LED ON)
```

## Data Flow
1. User clicks the "ON" or "OFF" button on the web interface.
2. The browser sends an HTTP GET request to the ESP32's local IP address.
3. The ESP32 parses the route and updates the digital state of GPIO 2.
4. The ESP32 responds with updated HTML reflecting the current LED state.

## Hardware
| Component | Description |
|-----------|-------------|
| ESP32 Development Board | Dual-core Wi-Fi & Bluetooth microcontroller |
| Onboard LED | Built-in blue LED for status indication |

## Software & Technologies
| Technology | Role |
|------------|------|
| Arduino IDE | Primary development environment |
| C++ | Firmware programming language |
| `WiFi.h` | Manages Wi-Fi connections |
| `WebServer.h` | Handles HTTP routing and client requests |

## Hardware Connections (Wiring)
| ESP32 Pin | Component |
|-----------|-----------|
| GPIO 2 | Onboard LED (Internal) |

## Wi-Fi Configuration
The firmware utilizes placeholder credentials for network authentication:
```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

## Implementation Workflow
The ESP32 initializes its serial port and connects to the specified Wi-Fi network. Once connected, it prints its dynamically assigned local IP address. The web server routes are then mapped to specific C++ callback functions, and the server begins listening for incoming client connections.

## Source Code Explanation
- `setup()`: Configures GPIO 2 as an `OUTPUT`, initializes Wi-Fi, and binds the `/`, `/on`, and `/off` HTTP routes.
- `loop()`: Continuously calls `server.handleClient()` to process incoming network traffic.
- Route Handlers: Functions like `handleOn()` execute `digitalWrite(2, HIGH)` and return an HTML string to the client.

## Testing
1. Uploaded firmware to the ESP32.
2. Monitored the Serial output to obtain the local IP address.
3. Entered the IP address into a mobile browser on the same Wi-Fi network.
4. Clicked the web buttons and verified the physical LED toggled instantly.

## Evidence
- *Note: Screenshots of the local web interface and hardware operation are preserved in the ProtoSem weekly report.*

## Challenges & Fixes
- **Wi-Fi Connectivity**: Intermittent connection drops were resolved by ensuring the board was within range of a stable 2.4GHz network.
- **State Synchronization**: Initially, refreshing the page did not reflect the true LED state. This was fixed by returning dynamic HTML based on `digitalRead(2)`.

## Key Learnings
- Mastered the configuration of ESP32 Wi-Fi credentials.
- Understood the mechanics of HTTP routing on microcontrollers.
- Successfully bridged software web interactions with physical hardware responses.

## Future Improvements
- Add mDNS support (e.g., `esp32.local`) so users don't need to memorize the IP address.
- Implement CSS styling for a more modern web interface.

## Reflection
This task served as an excellent entry point into IoT, highlighting how easily physical devices can be exposed to a local network. It paved the way for more complex, cloud-based architectures.

## Project Links
- [Task 1 Implementation Code](./ESP32_Onboard_LED_Control.ino)
- Developer: Harish Kumaran (ProtoSem Week 7)

## Conclusion
The ESP32 Web Server was successfully implemented, providing reliable local control over hardware. This foundational step is critical before moving to more advanced MQTT cloud integrations.
