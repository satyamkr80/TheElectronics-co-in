//Measurement of Capacitance using Arduino – An Interrupt-based Approach
//AUTHORS: SAIKAT PATRA, SHIBENDU MAHATA
//R1=R2=100KILOOHM

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
volatile unsigned long microseconds;
volatile float capacitance;

void setup() {
  lcd.begin(16, 2);
  pinMode(2,INPUT);
  Serial.begin(9600);
  attachInterrupt(0,cap,RISING);
    
}
void cap() {
  microseconds=micros()-microseconds;  
  capacitance=1.443*microseconds/300;
  capacitance = capacitance/1000;
  Serial.print(capacitance,3);
  Serial.println("uF");
  lcd.print("Capacitance:");
  lcd.setCursor(0, 1);
  lcd.print(capacitance,3);
  lcd.print("uF          ");
  microseconds=micros();
  
  }
void loop(){
}