# Real-Time Temperature Display with Raspberry Pi 4

## Project Overview
This project focuses on creating a real-time temperature monitoring system using a Raspberry Pi 4. The setup involves measuring ambient temperature with a sensor (using the I2C protocol) and displaying the readings on an SSD1306 OLED display (using the SPI protocol). The main objective is to deepen understanding of embedded systems through low-level programming, hardware interfacing, and writing custom drivers and libraries.

## Goals
- **Primary Goal**: Write custom SPI and I2C drivers in C for the Raspberry Pi 4.
- **Secondary Goal**: Develop a custom C library to interface with the SSD1306 OLED display, enabling text rendering, numeric output, and potentially advanced features like animations or scrolling text.
- **Minimum Viable Product (MVP)**: Display static text and numbers on the OLED screen.

## Features
- Real-time temperature monitoring.
- Custom SSD1306 driver for SPI communication.
- Custom library for rendering text and graphics on the OLED.
- Modular design to allow for future enhancements like animations and scrolling text.

## Hardware Components
1. Raspberry Pi 4
2. SSD1306 OLED Display
   - Resolution: 128x64 pixels
   - Communication: SPI protocol
3. Temperature Sensor (TBD)
   - Communication: I2C protocol
4. LCD1602 Second Display
   - Communication: TDB

## Software Components
- Programming Language: C
- Custom Drivers:
  - SPI driver for OLED communication.
  - I2C driver for temperature sensor communication.
- Libraries:
  - SSD1306 OLED library for handling display functionality.
- Testing: Validate the display setup using predefined SPI libraries (e.g., spidev) before transitioning to custom drivers.

## Setup
- Write Raspberry Pi Lite OS to MicroSD
- Install components:

## Future Enhancements
- Implement scrolling text and small animations.
- Add graphical elements like icons and patterns.
- Integrate advanced display features like partial updates and page addressing.
- Expand temperature monitoring functionality with configurable alerts.
