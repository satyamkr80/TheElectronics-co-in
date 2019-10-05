#include <SoftwareSerial.h>
SoftwareSerial SIM900(2, 3); // configure software serial port (rx, tx)

void setup()
{
SIM900.begin(2400);
Serial.begin(9600);
delay(2000); // give time to log on to network.
}

void loop()
{
SIM900.println("ATD + +9198xxxxxxxx;"); // Enter mobile number here to call
Serial.println("ATD + +9198xxxxxxxx;");
delay(100);
SIM900.println();
delay(30000); // wait for 30 seconds...
SIM900.println("ATH"); // disconnect after 30 second
Serial.println("ATH");
do {} while (1); // do nothing
}