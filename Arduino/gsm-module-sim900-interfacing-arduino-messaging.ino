#include <SoftwareSerial.h>
SoftwareSerial SIM900(2, 3);
 
void setup()
{
 SIM900.begin(2400);
 Serial.begin(9600);
 delay(2000); // give time to log on to network. 
}
 
void loop()
{
 SIM900.print("AT+CMGF=1\r"); 
Serial.print("AT+CMGF=1\r"); // AT command to send SMS message
 delay(2000);
 SIM900.println("AT + CMGS = \"+91xxxxxxxxxx\"");// recipient's mobile number
 Serial.println("AT + CMGS = \"+91xxxxxxxxxx\""); // recipient's mobile number
 delay(1000);
SIM900.println("Hello, world"); // message to send
Serial.println("Hello, world");
delay(200);
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
delay(200);
SIM900.println();
delay(5000); // give module time to send SMS
SIM900power();
do {} while (1);
}
