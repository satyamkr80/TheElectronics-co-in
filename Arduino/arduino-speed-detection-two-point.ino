#define green 9
#define red 8 
#include <LiquidCrystal.h>
unsigned long start,finish,total;
float seconds;
float full;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup() {
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  
  Serial.begin(9600);
  lcd.begin(16,2);
  

}
void displayResult()
{
  total=finish-start;
  Serial.println(total);
  seconds=total/1000;
  full=100.00/seconds;
  Serial.println(full);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Speed Is ");
  lcd.setCursor(5,1);
   lcd.print(full);
   lcd.print("mps");
   if(full>40)
  {
    Serial.println("High Speed");
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    
  }
  else{
    Serial.println("Normal Speed");
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }
  
}

void loop() {
  if(digitalRead(13)==LOW)
  {
   digitalWrite(red, LOW);
    digitalWrite(green, LOW);  
  start=millis();
  delay(200);
  Serial.println("started");
  }
  if(digitalRead(12)==LOW)
  {
  finish=millis();
  delay(200);
  Serial.println("Finished");
  displayResult();
  }

}