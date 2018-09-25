// LEDs
int red_x = 13;
int yellow_x = 12;
int green_x = 11;
int red_y = 10;
int yellow_y = 9;
int green_y = 8;

void setup() {
  pinMode(red_x, OUTPUT);
  pinMode(yellow_x, OUTPUT);
  pinMode(green_x, OUTPUT);
  pinMode(red_y, OUTPUT);
  pinMode(yellow_y, OUTPUT);
  pinMode(green_y, OUTPUT);
}

void loop() {
  // X-AXIS : turn off yellow, then turn red on for 5 seconds
  digitalWrite(yellow_x, LOW);
  digitalWrite(red_x, HIGH);
  // Y-AXIS : turn off red and yellow, then turn on green
  digitalWrite(yellow_y, LOW);
  digitalWrite(red_y, LOW);
  digitalWrite(green_y, HIGH);
  delay(25000);

  // X-AXIS : red and yellow on for 3 seconds (red is already on though)
  digitalWrite(yellow_x, HIGH);
  // Y-AXIS : green off, yellow for 3 seconds
  digitalWrite(yellow_y, HIGH);
  digitalWrite(green_y, LOW);
  delay(5000);

  // X-AXIS : turn off red and yellow, then turn on green
  digitalWrite(yellow_x, LOW);
  digitalWrite(red_x, LOW);
  digitalWrite(green_x, HIGH);
  // Y-AXIS : turn off yellow, then turn red on for 5 seconds
  digitalWrite(yellow_y, LOW);
  digitalWrite(red_y, HIGH);
  delay(25000);

  // X-AXIS : green off, yellow for 3 seconds
  digitalWrite(yellow_x, HIGH);
  digitalWrite(green_x, LOW);
  // Y-AXIS : red and yellow on for 3 seconds (red is already on though)
  digitalWrite(yellow_y, HIGH);
  delay(5000);
}
