I2C Communication between Raspberry Pi and Arduino
This project demonstrates how to establish I2C communication between a Raspberry Pi and an Arduino. The Arduino sends a string to the Raspberry Pi over I2C, and the Raspberry Pi receives and prints the string.

Overview
Arduino Code: Sets up the Arduino as an I2C slave device with address 0x8. The Arduino sends a string message ("Mohammed") to the Raspberry Pi when requested. The message is sent only once, after which it sends a space character or another indicator on subsequent requests.

Raspberry Pi Code: Uses the smbus library to communicate with the Arduino over I2C. It reads up to 32 bytes of data from the Arduino, filters out unwanted bytes (255 and 0), and constructs a string from the received bytes.
