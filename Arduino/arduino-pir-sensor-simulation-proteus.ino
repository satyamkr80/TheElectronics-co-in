void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  int pir=digitalRead(13);

  if (pir==HIGH)
  {
    Serial.println("Motion Detected");
    delay(1000);
  }
  else
  {
     Serial.println("No Motion");
    delay(1000);
  }
  // put your main code here, to run repeatedly:

}
