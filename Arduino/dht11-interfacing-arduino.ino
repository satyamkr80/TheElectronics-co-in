#include <dht.h>

dht DHT;

#define DHT11_PIN 4

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
   
  Serial.print("Temp = ");
  Serial.print(DHT.temperature);
  Serial.print(" ");
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println(" ");
  if(DHT.temperature > 35)
  {
   //put your condition here
  }
  else{
  //put your else condition here
  }
}