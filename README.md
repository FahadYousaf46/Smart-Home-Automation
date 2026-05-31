# 🏠 Smart Home Automation System

> An intelligent, automated environment control system built with **Arduino & C++**, demonstrating Object-Oriented Programming (OOP) principles applied to embedded hardware.

---

## Overview

Manual control of home appliances often leads to energy wastage and inefficiency. This system autonomously manages a **12V cooling fan** and **room lighting** based on real-time environmental data — temperature and light intensity — requiring **zero human intervention**.

---

## Hardware Components

- **Microcontroller:** Arduino Uno
- **Temperature & Humidity Sensor:** DHT11
- **Light Sensor:** LDR (Light Dependent Resistor)
- **Motor Driver:** L298N Module, powered via an external 12V adapter
- **Actuators:** 12V DC Cooling Fan & LED
- **Power Supply:** 12V DC Wall Adapter for the motor + 5V USB for the Arduino

---

## Software Architecture

The codebase is structured using core **OOP principles** in C++ for scalability and clean logic — not a flat procedural script.

- **Abstraction:** A base `Device` class defines a pure virtual `update()` function, establishing a standard interface for all hardware components.
- **Encapsulation:** Pin configurations, sensor reading logic, and actuator controls are bundled securely within self-contained `Light` and `Fan` classes.
- **Inheritance:** Both the `Light` and `Fan` classes extend the base `Device` class, reusing shared logic while implementing their own behavior.

---

## How It Works

1. The **DHT11 sensor** continuously monitors room temperature. If it exceeds **37°C**, the L298N motor driver activates the 12V fan.
2. The **LDR sensor** monitors ambient light levels. If the analog reading drops below **300**, the LED turns on automatically.
3. Both devices **power down automatically** once conditions return to normal.

---

## Repository Contents

- `SmartHomeAutomation.ino` — Complete object-oriented C++ source code
- `OOP-Presentation.pdf` — Project slides with block diagrams and flowcharts

---

