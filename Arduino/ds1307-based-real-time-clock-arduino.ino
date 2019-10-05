#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
RTC_DS1307 RTC;

void setup () {
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();
     lcd.begin(20,4);
   
  
   pinMode(13,OUTPUT);
   digitalWrite(13,LOW);
 
  if (! RTC.isrunning()) 
  {
   Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
  RTC.adjust(DateTime(__DATE__, __TIME__));
   
  }
}
 
void loop () {
  
 
    DateTime now = RTC.now();
    

    if(now.hour()>11)
    {
     lcd.setCursor(14, 1);
    lcd.print("PM"); 
  }
   else
  {
    lcd.setCursor(14, 1);
    lcd.print("AM"); 
  }
  
    lcd.setCursor(0, 0);
    lcd.print("Date-");
    lcd.print(now.day(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.year(), DEC);
    lcd.print(' ');
    lcd.setCursor(0, 1);
     if (now.hour()<10)
     
    lcd.print('0');
    lcd.print("Time-");
    if(now.hour()>12)
    {
    lcd.print(now.hour()-12, DEC);
    }
    else
    {
     lcd.print(now.hour(), DEC);
    } 
    lcd.print(':');
     if (now.minute()<10)
    lcd.print('0');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    if (now.second()<10)
    lcd.print('0');
    lcd.print(now.second(), DEC);
    lcd.setCursor(0, 3);
   int dayofweek = now.dayOfWeek();
   switch(dayofweek){
     case 1:
     lcd.print("Monday");
     break;
     case 2:
     lcd.print("Tuesday");
     break;
     case 3:
     lcd.print("Wednesday");
     break;
     case 4:
     lcd.print("Thursday");
     break;
     case 5:
     lcd.print("Friday");
     break;
     case 6:
     lcd.print("Saturday");
     break;
     case 0:
     lcd.print("Sunday");
     break;
    delay(1000);
}
 
}