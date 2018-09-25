int red = 13;
int yellow = 12;
int green = 11;
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(trigPin, OUTPUT); // sets the trigPin as an output
  pinMode(echoPin, INPUT); // sets the echo as an input
  Serial.begin(9600); // starts the serial communication
}

void loop() {
  // clears the trigPin
  digitalWrite(trigPin, LOW);
  delay(2);

  // sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  // reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // calculating the distance
  distance = duration*0.034/2;

  // prints the distance on the serial monitor
  Serial.println("Distance: ");
  Serial.println(distance);
  if (distance<=25) {
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }
  if ((distance<=50) && (distance>25)) {
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
  }
  if (distance>50) {
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }
}
