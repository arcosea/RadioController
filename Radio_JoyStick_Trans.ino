

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

// Set radio driver to NRF24 & client address to 1
RHReliableDatagram RadioManager(RadioDriver, CLIENT_ADDRESS);

// Declare unsigned 8-bit joystick array (x,y,dir)
uint8_t joystick[3];

// Declare message buffer
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];

void setup() {
  // Setup serial monitor
  Serial.begin(9600);

  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if(!RadioManager.init()){ 
    Serial.println("init failed");
  }

}

void loop() {
  // Print Serial Monitor
  Serial.println("Reading joystick values ");

  // Read joystick values and map values of 0 to 255
  joystick[0] = map(analogRead(JoyStick_X_PIN), 0, 1023, 0, 255);
  joystick[1] = map(analogRead(JoyStick_Y_PIN), 0, 1023, 0, 255);
  joystick[2] = 100;

  // Display joystick values in serial monitor
  Serial.println("---------------------");
  Serial.print("X: "); Serial.println(joystick[0]);
  Serial.print("Y: "); Serial.println(joystick[1]);

  // Send message containing joystick data to manager server
  if(RadioManager.sendtoWait(joystick, sizeof(joystick), SERVER_ADDRESS)){
      // Wait for reply
      uint8_t len = sizeof(buf);
      uint8_t from;
      if(RadioManager.recvfromAckTimeout(buf, &len, 2000, &from)){
        Serial.print("got reply from : 0x");
        Serial.print(from, HEX);
        Serial.print(": ");
        Serial.println((char*)buf);
      } else{
        Serial.println("No reply, is nrf24_reliable_datagram_server running?");
      }
  }

}
