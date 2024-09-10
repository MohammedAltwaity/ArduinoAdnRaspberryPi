#include <Wire.h>

const int ledPin = 13; 
String message = "Mohammed"; 
bool hasSentMessage = false;  

void setup() {
  // Join I2C bus as a slave with address 8
  Wire.begin(0x8);
  
  // Call requestEvent when the master requests data
  Wire.onRequest(requestEvent);
  
  // Setup pin 13 as output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Do nothing, waiting for the master to request data
}

// Function to send data when the master requests
void requestEvent() {
  if (!hasSentMessage) {
    Wire.write(message.c_str());  // Send the string as bytes
    hasSentMessage = true;  // Set the flag so the message is not sent again
  } else {
    // Optionally send something else or nothing if requested again
    Wire.write(" ");  // Send a single space or another indicator
  }
}
