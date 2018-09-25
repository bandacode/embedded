#include <Servo.h>
#include <Password.h>
#include <Keypad.h>
#include <SoftwareSerial.h>

// used for GSM module to contact home owner when alarm goes off
SoftwareSerial mySerial(10, 11); // RX, TX
String HOME_OWNER_NUMBER = "Your Phone Number Goes Here"

String newPasswordString; //hold the new password
char newPassword[6]; //charater string of newPasswordString

//initialize password to 123456
//you can use password.set(newPassword) to overwrite it
Password password = Password( "123456" );

byte maxPasswordLength = 6;
byte currentPasswordLength = 0;

const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 9, 8, 7, 6 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { A1, A2, A3 };

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

/*
 * buttonPin is connected to a button for arming/disarming the system
 * servoPin is connected to a servo motor whick locks/unlocks a door
 * ledPin is connected to an LED that flashes for a visual alarm
 * speakerPin is connected to a buzzer for an audible alarm
 * tempPin is connected to a resistance temperature detector (RTD)
 * maxTemp is the value for maximum temperature before the fire alarm goes off
 * 
 */
int buttonPin = 4;
int servoPin = 3;
int ledPin = 13;
int speakerPin = 5;
float temp;
float maxTemp = 35.0;
int tempPin = 0;
int inputPin = 2;
int val = 0;
int tempBuffer = 0;
Servo servo;

/*
 * boolean values to track the current state of the security system:
 * isArmed - when the system is armed
 * isRinging - when the alarms have been triggered
 * called - status of whether a phone call has been placed out notifying the home owner
 */
bool isArmed = false;
bool isRinging = true;
bool called = false;

void setup() {
  servo.attach(servoPin);
  servo.write(0);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  isTriggered();
  temp = analogRead(tempPin);
  temp *= 0.48828125;
  if (temp >= maxTemp) {
    tempBuffer++;
    Serial.println(temp);
    if (tempBuffer >= 1000) {
      while (isRinging) {
        Serial.println("FIRE ALERT!");
        alarm(1);
        isTriggered();
        if (!called) {
          call();
        }
      }
      tempBuffer = 0;
    }
  }
  if (isArmed) {
    val = digitalRead(inputPin);
    if (val == HIGH) {
      while (isRinging) {
        Serial.println("Motion detected...");
        alarm(0);
        isTriggered();
        if (!called) {
          call();
        }
      }
    }
  }
}

/* 
 *  checks for the various states of the system:
 *  - whether the password has been entered, changed or reset
 *  - whether the arming button has been pressed
 */
void isTriggered() {
  char key = kpd.getKey();
  if (key != NO_KEY) {
    delay(60);
    Serial.print(key);
    switch (key) {
      case '#': resetPassword(); break;
      case '*': checkPassword(); break;
      default: processNumberKey(key);
    }
  }
  if (digitalRead(buttonPin) == LOW) {
    if (!isArmed) {
      trigger1();
    } else {
      trigger0();
    }
  }
}

// disables/deactivates the alarm
void trigger0() {
  unlock();
  digitalWrite(ledPin, LOW);
  isArmed = false;
  isRinging = false;
  called = false;
}

// enables/activates the alarm
void trigger1() {
  lock();
  digitalWrite(ledPin, HIGH);
  isArmed = true;
  isRinging = true;
}

// turns the servo motor to lock a door
void lock() {
  servo.write(90);
}

// turns the servo motor to unlock a door
void unlock() {
  servo.write(0);
}

void processNumberKey(char key) {
  currentPasswordLength++;
  password.append(key);
  if (currentPasswordLength == maxPasswordLength) {
    checkPassword();
  }
}

void checkPassword() {
  if (password.evaluate()) {
    if (!isArmed) {
      trigger1();
    } else {
      trigger0();
    }
  }
  resetPassword();
}

void resetPassword() {
  password.reset();
  currentPasswordLength = 0;
}

// alarm function that dictates the behaviour of the system once the alarm is activated
void alarm(int i) {
  // intruder
  if (i == 0) {
    digitalWrite(speakerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(speakerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  // fire
  if (i == 1) {
    unlock();
    digitalWrite(speakerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(speakerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(150);
  }
}

// calls the home owner to notify them of an intruder or fire alert
void call() {
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  delay(2000);HOME_OWNER_NUMBER
  mySerial.print("ATD;");
  mySerial.print(HOME_OWNER_NUMBER);
  mySerial.println(";");
  called = true;
}
