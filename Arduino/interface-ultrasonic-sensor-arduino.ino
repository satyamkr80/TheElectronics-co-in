#define trigPin 12
#define echoPin 13

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup()
{
lcd.begin(16, 2);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.setCursor(1,0);
lcd.print("Distance=");
}

void loop()
{
long duration, distance;
digitalWrite(trigPin, LOW); // Added this line
delayMicroseconds(2); // Added this line
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); // Added this line
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1; // conversion in cm
lcd.setCursor(11,0);
lcd.print(distance); //output on lcd in centimeter
lcd.setCursor(14,0);
lcd.print("cm");
}
