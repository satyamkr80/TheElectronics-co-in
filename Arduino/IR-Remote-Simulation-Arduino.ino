// Code By Satyam Singh

#include <IRremote.h>

#define PIN_RECEIVER 2   // Signal Pin of IR receiver
#define LED 3

IRrecv receiver(PIN_RECEIVER);


void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  receiver.enableIRIn(); // Start the receiver
}

void loop()
{
  // Checks received an IR signal
  if (receiver.decode()) {
    int data = receiver.decodedIRData.command;
    //Serial.println(data);
    receiver.resume();  // Receive the next value
    if(data== 48){
      digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED, LOW);
    }
  }
}

