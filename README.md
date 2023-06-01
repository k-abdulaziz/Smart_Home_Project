# Smart_Home_Project

Welcome to the Smart Home project! This project aims to create a smart and automated home system using the Atmega32 microcontroller. The Smart Home Master utilizes various peripherals and external modules to provide a comprehensive home automation solution.

![https://imgur.com/a/mmRmdXB](https://i.imgur.com/UCgl0aM.gif)

## Overview

The Smart Home Master project leverages the power of the Atmega32 microcontroller as the central control unit. It offers a range of features and capabilities, including GPIO (General-Purpose Input/Output) pins, communication interfaces such as USART and TWI (I2C), ADC (Analog-to-Digital Converter), external interrupt handling, and advanced timer units.

The project incorporates a variety of peripherals and modules to enable different functionalities within the smart home system. These include:

### Peripherals

- **DIO (Digital Input/Output):** Provides digital communication with various devices and components, allowing control and sensing of signals.
- **TWI (I2C - Two-Wire Interface):** Facilitates communication with I2C compatible devices, such as sensors and other modules.
- **ADC (Analog-to-Digital Converter):** Converts analog sensor signals into digital data, enabling precise measurement and monitoring of analog parameters.
- **External Interrupt (EXTI):** Allows interrupt-based handling of external events, such as button presses or sensor triggers.
- **GIE (Global Interrupt Enable):** Controls the enabling and disabling of interrupts globally, ensuring proper interrupt handling.
- **Timer1 Input Capture Unit (ICU):** Captures and measures external signals' time duration, useful for applications like measuring pulse widths or frequency calculations.

### Modules

- **EEPROM (Electrically Erasable Programmable Read-Only Memory):** Provides non-volatile memory for storing critical system data that persists even when power is turned off.
- **LCD (Liquid Crystal Display):** Offers a visual interface for displaying system information, status, and user prompts.
- **Keypad:** Enables users to input commands and interact with the smart home system easily.
- **DC Motor:** Controls the movement of various mechanisms in the smart home setup, such as window blinds or door locks.
- **Servo Motor:** Allows precise control of angles, making it ideal for applications like robotic arm movement or motorized door locks.
- **LEDs:** Used for visual feedback, indication, and status display in the smart home system.
- **Buzzer:** Produces audible alerts, notifications, and sounds to indicate certain events or conditions.
- **Push Button:** Provides a mechanism for manual control or system reset.

## Getting Started

Follow these steps to set up and run the Smart Home project:

### Prerequisites

- Atmega32 microcontroller development board
- Required peripherals and modules (as listed above)
- AVR-GCC toolchain for compiling and uploading code to the microcontroller
- Atmel Studio or any other compatible IDE for editing and debugging the code

### Installation

1. Clone the repository or download the source code as a ZIP file.
```
git clone https://github.com/k-abdulaziz/Smart_Home_Project.git
```
2. Open the project in Atmel Studio or your preferred IDE.
3. Connect the peripherals and modules to the Atmega32 microcontroller according to the provided schematics and pin configurations.
4. Compile the code and upload it to the microcontroller using the AVR-GCC toolchain or the built-in tools in your IDE.

### Usage

1. Power on the Atmega32 microcontroller and the connected peripherals and modules.
2. Use the keypad to input commands and interact with the smart home system.
3. Monitor the LCD for system information, status updates, and user prompts.
4. Observe the LEDs, buzzer, and other components for visual and audible feedback.

## Contributing

We welcome contributions to the Smart Home Master project! If you would like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch with a descriptive name for your feature or bugfix.
3. Commit your changes to the new branch.
4. Submit a pull request to the main repository, and provide a clear description of your changes.

## License

This project is licensed under the MIT License.

## Acknowledgments

- The Atmega32 microcontroller community for providing valuable resources and support.
- All contributors who have helped improve the Smart Home Master project.
