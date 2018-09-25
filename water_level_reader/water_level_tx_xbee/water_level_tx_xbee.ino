#include <Ultrasonic.h>

long waterLevel;

#define TRIGGER_PIN 30
#define ECHO_PIN 31
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  waterLevel = ultrasonic.distanceRead();
  Serial.print('<');  //Starting
  Serial.print(waterLevel);
  Serial.println('>');//Ending symbol
  delay(1000);
}
