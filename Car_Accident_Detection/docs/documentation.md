# Car Accident Detection, GPS, and Alert System

## Introduction
This project develops a car accident detection and alert system using the NodeMCU/ESP8266 microcontroller, ADXL345 accelerometer, GY-NEO6MV2 GPS module, and SIM800L GSM module. The system detects accidents by monitoring sudden changes in acceleration, retrieves the vehicle's location, and sends an emergency alert with coordinates to predefined contacts.

## Principle
The system uses:
- **ADXL345 Accelerometer**: Detects abrupt acceleration changes (e.g., >3g) to identify accidents.
- **GY-NEO6MV2 GPS Module**: Provides real-time latitude and longitude coordinates.
- **SIM800L GSM Module**: Sends SMS or makes calls to emergency contacts with accident details and location.
- **NodeMCU/ESP8266**: Controls all components and processes data.

When an accident is detected (tilt exceeds 45°), the system sends an SMS with a Google Maps link and initiates a call.

## Objectives
1. Detect significant acceleration changes indicating an accident.
2. Obtain accurate geographical location using GPS.
3. Send SMS or call emergency contacts with location details.
4. Ensure system reliability in real-time scenarios.

## Equipment
- **NodeMCU/ESP8266**: 32-bit RISC CPU, 80/160 MHz, 4 MB flash.
- **ADXL345 Accelerometer**: 3-axis, I2C/SPI, ±2g/±4g/±8g/±16g range.
- **GY-NEO6MV2 GPS Module**: UART, 9600 baud rate, <2.5m accuracy.
- **SIM800L GSM Module**: Quad-band, 3.4-4.4V, UART.
- **Breadboard and Wires**: For prototyping.
- **External Power Source**: 4V, 2A for SIM800L.

## Circuit Diagram
![Circuit Diagram](Car_Accident_Detection_Circuit_Diagram.jpg)

## Applications
- Enhances emergency response by providing exact accident locations.
- Integrates into vehicle safety systems.
- Useful for fleet management and individual car owners.
- Foundation for further automotive safety research.

## Setup Instructions
1. Connect components as per the circuit diagram.
2. Install required libraries: `Adafruit_Sensor`, `Adafruit_ADXL345_U`, `TinyGPS++`, `SoftwareSerial`.
3. Upload the `CarAccidentDetection.ino` sketch to the NodeMCU.
4. Configure phone numbers in the code.
5. Test the system by simulating an accident (tilting the accelerometer).

## Notes
- Ensure the SIM800L has a valid SIM card with SMS/call capabilities.
- Verify GPS module placement for clear satellite reception.
- Adjust `tiltThreshold` as needed for sensitivity.
