#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

//Variables
bool started = false; //True: Message is strated
bool ended  = false;//True: Message is finished
char incomingByte ; //Variable to store the incoming byte
char msg[4];    //Message - array from 0 to 3 (4 values - mBar - e.g. 9240)
byte index;     //Index of array

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.println("Water Level:    ");
}

void loop() {
  while (Serial.available() > 0) {
    //Read the incoming byte
    incomingByte = Serial.read();
    //Start the message when the '<' symbol is received
    if (incomingByte == '<')    {
      started = true;
      index = 0;
      msg[index] = '\0'; // Throw away any incomplete packet
    }
    //End the message when the '>' symbol is received
    else if (incomingByte == '>')   {
      ended = true;
      break; // Done reading - exit from while loop!
    }
    //Read the message!
    else   {
      if (index < 5) // Make sure there is room
      {
        msg[index] = incomingByte; // Add char to array
        index++;
        msg[index] = '\0'; // Add NULL to end
      }
    }
  }

  if (started && ended) {
    int value = atoi(msg);
    lcd.setCursor(0, 1);
    lcd.print(value);
    lcd.println(" cm         ");
    //Serial.println(value); //Only for debugging
    index = 0;
    msg[index] = '\0';
    started = false;
    ended = false;
  }
}
