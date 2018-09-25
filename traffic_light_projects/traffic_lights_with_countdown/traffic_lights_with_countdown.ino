int a = 0; // for displaying segment "a"
int b = 1; // for displaying segment "b"
int c = 2; // for displaying segment "c"
int d = 3; // for displaying segment "d"
int e = 4; // for displaying segment "e"
int f = 5; // for displaying segment "f"
int g = 6; // for displaying segment "g"

// LEDs
int red_x = 13;
int yellow_x = 12;
int green_x = 11;
int red_y = 10;
int yellow_y = 9;
int green_y = 8;

void setup() {
  pinMode(a, OUTPUT); // A
  pinMode(b, OUTPUT); // B
  pinMode(c, OUTPUT); // C
  pinMode(d, OUTPUT); // D
  pinMode(e, OUTPUT); // E
  pinMode(f, OUTPUT); // F
  pinMode(g, OUTPUT); // G
  
  pinMode(red_x, OUTPUT);
  pinMode(yellow_x, OUTPUT);
  pinMode(green_x, OUTPUT);
  pinMode(red_y, OUTPUT);
  pinMode(yellow_y, OUTPUT);
  pinMode(green_y, OUTPUT);
}

void loop() {
  // X-AXIS : turn off yellow, then turn red on for 9 seconds
  digitalWrite(green_x, LOW);
  digitalWrite(yellow_x, LOW);
  digitalWrite(red_x, HIGH);
  // Y-AXIS : turn off red and yellow, then turn on green
  digitalWrite(yellow_y, LOW);
  digitalWrite(red_y, LOW);
  digitalWrite(green_y, HIGH);
  for(int i=9; i>=0;i--) {
    displayDigit(i);
    delay(1000);
    turnOff();
  }

  // Y-AXIS : green off, yellow for 5 seconds
  digitalWrite(yellow_y, HIGH);
  for(int i=5; i>=0;i--) {
    displayDigit(i);
    delay(1000);
    turnOff();
  }

  // X-AXIS : turn off red and yellow, then turn on green
  digitalWrite(yellow_x, LOW);
  digitalWrite(red_x, LOW);
  digitalWrite(green_x, HIGH);
  // Y-AXIS : turn off yellow, then turn red on for 5 seconds
  digitalWrite(green_y, LOW);
  digitalWrite(yellow_y, LOW);
  digitalWrite(red_y, HIGH);
  for(int i=9; i>=0;i--) {
    displayDigit(i);
    delay(1000);
    turnOff();
  }

  // X-AXIS : green off, yellow for 3 seconds
  digitalWrite(yellow_x, HIGH);
  for(int i=5; i>=0;i--) {
    displayDigit(i);
    delay(1000);
    turnOff();
  }
}

void displayDigit(int digit) {
  // conditions for displaying segment a
  if(digit != 1 && digit != 4)
  digitalWrite(a, HIGH);

  // conditions for displaying segment b
  if(digit != 5 && digit != 6)
  digitalWrite(b, HIGH);

  // conditions for displaying segment c
  if(digit != 2)
  digitalWrite(c, HIGH);

  // conditions for displaying segment d
  if(digit != 1 && digit != 4 && digit != 7)
  digitalWrite(d, HIGH);

  // conditions for displaying segment e
  if(digit == 2 || digit == 6 || digit == 8 || digit == 0)
  digitalWrite(e, HIGH);

  // conditions for displaying segment f
  if(digit != 1 && digit != 2 && digit != 3 && digit != 7)
  digitalWrite(f, HIGH);

  // conditions for displaying segment g
  if(digit != 0 && digit != 1 && digit != 7)
  digitalWrite(g, HIGH);
}

// turns off all the segments of the 7-segment display
void turnOff() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
