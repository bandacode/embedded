#include <LiquidCrystal.h>
#include <DHT.h>;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

//Constants
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

/*
 * pump sprays water when humidity is low
 * bulb turns on when temperature is low
 * fan turns on when temperature is too high
 */
int pump = 9;
int bulb = 10;
int fan = 11;

//Variables
float hum;  //Stores humidity value
float minHum = 45.00;
float maxHum = 75.00;
float temp; //Stores temperature value
float maxTemp = 26.00;
float minTemp = 16.00;

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  pinMode(pump, OUTPUT);
  pinMode(bulb, OUTPUT);
  pinMode(fan, OUTPUT);
}

void loop() {
  delay(2000);
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  //Print temp and humidity values to lcd
  lcd.setCursor(0, 0);
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print(" %");
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.println(" C");
  delay(2000);

  if (hum <= minHum) {
    digitalWrite(pump, HIGH);
    delay(1000);
    digitalWrite(pump, LOW);
    digitalWrite(bulb, LOW);
  }
  if (hum >= maxHum) {
    digitalWrite(bulb, HIGH);
  }
  if (temp < minTemp) {
    digitalWrite(bulb, HIGH);
    digitalWrite(fan, LOW);
  }
  if (temp > maxTemp) {
    digitalWrite(bulb, LOW);
    digitalWrite(fan, HIGH);
  }
}
