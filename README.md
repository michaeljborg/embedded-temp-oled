# Real-Time Temperature Display with Raspberry Pi 4

## Project Overview
This project focuses on creating a real-time temperature monitoring system using a Raspberry Pi 4. The setup involves measuring ambient temperature with a sensor (using the I2C protocol) and displaying the readings on an SSD1306 OLED display (using the SPI protocol). The main objective is to deepen understanding of embedded systems through low-level programming, hardware interfacing, and writing custom drivers.

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
4. Additional Supplies: Breadboard, wires, and connectors for prototyping.

## Software Components
- Programming Language: C
- Custom Drivers:
  - SPI driver for OLED communication.
  - I2C driver for temperature sensor communication.
- Libraries:
  - SSD1306 OLED library for handling display functionality.
- Testing: Validate the display setup using predefined SPI libraries (e.g., spidev) before transitioning to custom drivers.

## Project Structure
```
real-time-temp-display/
├── src/
│   ├── main.c               # Main program
│   ├── spi_driver.c         # Custom SPI driver
│   ├── i2c_driver.c         # Custom I2C driver
│   ├── ssd1306.c            # SSD1306 library
│   └── ssd1306.h            # Header file for SSD1306 library
├── include/
│   ├── spi_driver.h         # Header file for SPI driver
│   ├── i2c_driver.h         # Header file for I2C driver
├── README.md
├── LICENSE
└── Makefile
```

## Future Enhancements
- Implement scrolling text and small animations.
- Add graphical elements like icons and patterns.
- Integrate advanced display features like partial updates and page addressing.
- Expand temperature monitoring functionality with configurable alerts.
