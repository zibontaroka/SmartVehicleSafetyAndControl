# Bluetooth Controlled Four Wheel Car

## Introduction
This project creates a four-wheel car controlled via Bluetooth using an Arduino Uno, HC-05 Bluetooth module, L298N motor driver, and four DC motors. The car can move forward, backward, left, right, and in diagonal directions based on commands sent from a smartphone.

## Principle
The system uses:
- **Arduino Uno**: Controls the motors and processes Bluetooth commands.
- **HC-05 Bluetooth Module**: Receives commands wirelessly from a smartphone.
- **L298N Motor Driver**: Controls the speed and direction of four DC motors.
- **DC Motors**: Drive the car’s wheels.

Commands (e.g., 'F' for forward, 'B' for backward) are sent via Bluetooth to control the car’s movement.

## Objectives
1. Enable wireless control of a four-wheel car via Bluetooth.
2. Implement precise motor control for various directions and speeds.
3. Ensure reliable communication between the smartphone and the car.

## Equipment
- **Arduino Uno**: General-purpose microcontroller.
- **HC-05 Bluetooth Module**: Bluetooth V2.0+EDR, 3.6-6V.
- **L298N Motor Driver**: Dual H-Bridge, 5-35V, 2A per channel.
- **DC Motors (x4)**: 6-12V, 100-300 RPM.
- **Battery Pack**: Typically 11.1V LiPo battery.
- **Breadboard/PCB and Jumper Wires**: For connections.

## Circuit Diagram
![Circuit Diagram](Bluetooth_Controlled_Car_Circuit_Diagram.jpg)

## Applications
- Educational tool for learning robotics and Bluetooth communication.
- Basis for advanced robotic projects with wireless control.
- Hobby projects for remote-controlled vehicles.

## Setup Instructions
1. Connect components as per the circuit diagram.
2. Install the `AFMotor` library in the Arduino IDE.
3. Upload the `BluetoothControlledCar.ino` sketch to the Arduino Uno.
4. Pair the HC-05 module with a smartphone and use a Bluetooth terminal app to send commands.
5. Test the car’s movement with commands: 'F' (forward), 'B' (back), 'L' (left), 'R' (right), 'I' (top-right), 'J' (top-left), 'K' (bottom-right), 'M' (bottom-left), 'T' (stop).

## Notes
- Ensure the battery pack provides sufficient voltage and current.
- Verify HC-05 Bluetooth pairing before testing.
- Adjust `Speeed` value in the code for motor speed control.