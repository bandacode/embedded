#include <Ultrasonic.h>
#include "RF24.h"

byte addresses[][6] = {"1Node", "2Node"};

RF24 radio(7, 8);

#define TRIGGER_PIN 30
#define ECHO_PIN 31
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

struct dataStruct {
  unsigned long _micros;
  float value;
} waterLevel;

void setup() {
  Serial.begin(115200);
  Serial.println(F("Water Level Transmitter"));
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(addresses[1]);
  waterLevel.value = 1.22;
  delay(100);
}

void loop() {
  int distance = ultrasonic.distanceRead();
  Serial.print("water level = ");
  Serial.print(distance);
  Serial.println(" cm");
  waterLevel.value = distance;
  radio.write( &waterLevel, sizeof(waterLevel) );
  delay(1000);
}
