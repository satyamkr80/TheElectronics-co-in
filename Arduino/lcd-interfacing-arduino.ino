
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
   lcd.setCursor(0, 0);
  lcd.print("hello, world!");
   lcd.setCursor(0, 1);
   lcd.print("The Electronics");
  
}

void loop() {
 
 //Your loop code here
}

