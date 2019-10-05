/*
* Arduino 4x7 LED Display
* Displays numbers ranging from 0 through 1023
* Test Code displays the value of a sensor connected to the analog input A0
*/
// bits representing segments A through G (and decimal point) for numerals 0-9
const int numeral[10] = {
   //ABCDEFG /dp
   B11111100, // 0
   B01100000, // 1
   B11011010, // 2
   B11110010, // 3
   B01100110, // 4
   B10110110, // 5
   B00111110, // 6
   B11100000, // 7
   B11111110, // 8
   B11100110, // 9
};
// pins for decimal point and each segment
// DP,G,F,E,D,C,B,A
const int segmentPins[] = { 13,8,7,6,5,4,3,2 };
const int nbrDigits= 4; // the number of digits in the LED display
//dig 0 1 2 3
const int digitPins[nbrDigits] = { 9,10,11,12 };
void setup()
{
   for(int i=0; i < 8; i++) {
      pinMode(segmentPins[i], OUTPUT); // set segment and DP pins to output
   }
   for(int i=0; i < nbrDigits; i++) {
      pinMode(digitPins[i], OUTPUT);
   }
} 
 
void loop()
{
   int value = analogRead(0);
   showNumber(value);
} 
 
void showNumber( int number)
{
   if(number == 0) {
      showDigit( 0, nbrDigits-1) ; // display 0 in the rightmost digit
   } else {
      // display the value corresponding to each digit
      // leftmost digit is 0, rightmost is one less than the number of places
      for( int digit = nbrDigits-1; digit >= 0; digit--)  {
         if(number > 0)  {
            showDigit( number % 10, digit) ;
            number = number / 10;
         }
      }
   }
} 
 
// Displays given number on a 7-segment display at the given digit position
void showDigit( int number, int digit)
{
   digitalWrite( digitPins[digit], HIGH );
   for(int segment = 1; segment < 8; segment++)  {
      boolean isBitSet = bitRead(numeral[number], segment);
      // isBitSet will be true if given bit is 1
      // isBitSet = ! isBitSet; // Code Option*
      // uncomment the above Code Option line for common anode display
      digitalWrite( segmentPins[segment], isBitSet);
   }
   delay(5);
   digitalWrite( digitPins[digit], LOW );
}