#include <IRremote.h>

int IRpin = 6;  // pin for the IR sensor
int motor = 13;    // motor pin
IRrecv irrecv(IRpin);
decode_results results;

boolean motorOn = true; // initializing motorOn as true

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(motor, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 16753245) { // this is where you put in your IR remote button #
      if (motorOn == true)  { // is motorOn equal to true?
        motorOn = false;
        digitalWrite(motor, HIGH);
        delay(100);      // keeps the transition smooth
      }
      else {
        motorOn = true;
        digitalWrite(motor, LOW);
        delay(100);
      }
    }
    irrecv.resume();   // Receive the next value
  }
}
