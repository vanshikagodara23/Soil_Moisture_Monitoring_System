# Soil Moisture Monitoring System

IoT soil moisture monitor using an ESP32 and the Blynk app. The moisture reading is sent to Blynk every 2 seconds so it can be watched from a phone.

## How it works

- The ESP32 connects to WiFi and then to Blynk.
- Every 2 seconds it reads the soil moisture sensor on pin 34.
- The value is printed on the Serial Monitor and sent to Blynk virtual pin **V0**.

A higher reading means drier soil (for most capacitive and resistive sensors).

## Components

- ESP32 development board
- Soil moisture sensor (analog output)
- Jumper wires

## Wiring

| Part | Pin | ESP32 pin |
|---|---|---|
| Soil sensor | AO (analog out) | 34 |
| Soil sensor | VCC / GND | 3.3V / GND |

## Libraries

- Blynk

## Setup

1. Create a template and device in the Blynk app or website.
2. Add a datastream on virtual pin **V0** and a gauge or chart widget for it.
3. Fill in these values in the code:

```cpp
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";
```

## How to run

1. Install the **Blynk** library from the Library Manager.
2. Select an ESP32 board in the Arduino IDE.
3. Upload and open the Serial Monitor at 115200 baud.
4. Open the Blynk app to see the live readings.
