#include <SPI.h>
#include "RF24.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7, 8);
/**********************************************************/

byte addresses[][6] = {"1Node", "2Node"};

struct dataStruct {
  unsigned long _micros;
  float value;
} waterLevel;

void setup() {
  Serial.begin(115200);
  lcd.begin(16,2);
  Serial.println(F("Water Level Receiver"));
  lcd.println("Water Level:    ");
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  // Open a writing and reading pipe on each radio, with opposite addresses
  radio.openReadingPipe(1, addresses[1]);
  // Start the radio listening for data
  radio.startListening();
}

void loop() {
  if ( radio.available()) {
    // Variable for the received timestamp
    while (radio.available()) { // While there is data ready
      radio.read( &waterLevel, sizeof(waterLevel) ); // Get the payload
    }
    Serial.println("Water level:");
    Serial.println(waterLevel.value);
    lcd.setCursor(0,1);
    lcd.print(waterLevel.value);
    lcd.println(" cm         ");
  }
}
