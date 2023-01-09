


// Include RadioHead Reliable DataGram & NRF24 libraries
#include <RHReliableDatagram.h>
#include <RH_NRF24.h>

// Include Dependant SPI Library
#include <SPI.h>

// Define JoyStick Connections
#define JoyStick_X_PIN      A1
#define JoyStick_Y_PIN      A2

// Define Addresses for radio channels
#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

// Create instance of radio driver
RH_NRF24 RadioDriver;

// Set radio driver to NRF24 & servier address to 2
RHReliableDatagram RadioManager(RadioDriver, SERVER_ADDRESS);

// Define message to return if values recievered
uint8_t ReturnMessage[] = "JoyStick Data Received";

// Define message buffer
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];


void setup() {
  // Begin monitor
  Serial.begin(9600);

  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if(!RadioManager.init()){ 
    Serial.println("init failed");
  }

}

void loop() {
  // Radio available
  if(RadioManager.available()){
    // Wait for message addressed to use from transmitter
    uint8_t len = sizeof(buf);
    uint8_t from;
    if(RadioManager.recvfromAck(buf, &len, &from)){
      // Print Serial Values
      Serial.print("Got request from : 0x");
      Serial.print(from, HEX);
      Serial.print(": X = ");
      Serial.print(buf[0]);
      Serial.print(": Y = ");
      Serial.print(buf[1]);
       Serial.print(": Z = ");
      Serial.print(buf[2]);

      // Send reply back to original trans, check for error
      if(!RadioManager.sendtoWait(ReturnMessage, sizeof(ReturnMessage), from)){
        Serial.println("sendWait failed");
      }
    }
  }

}
