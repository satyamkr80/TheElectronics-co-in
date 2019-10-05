void setup(){
  //Initialise the LEDPins to OUTPUT
  for(int i=4; i<14; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  redYellow(3);  //3 replicates of the redYellow sequence
  curtain(2);    //2 replicates of the curtain sequence
  fastSlow(2);   //2 replicates of the fastSlow sequence
}

void redYellow(int Reps){
  for(int k=1; k<(Reps+1); k++){
    for(int i=4; i<14; i=i+2){
      blink(i,200,20);              //Call the blink method below
    }
    for(int i=13; i>3; i=i-2){
      blink(i,200,10);              //Call the blink method below
    }
  }
}

void curtain(int Reps){
  for(int k=1; k<(Reps+1); k++){
    for(int j=1; j<257; j=j+j){
      int LEDCounter=1;
      int LEDSwitch=1;
      for(int ledPin=4; ledPin>3 && ledPin<14; ledPin=ledPin+LEDCounter){
        if(LEDSwitch){
          digitalWrite(ledPin, HIGH);
          delay(j);
        }else{
          digitalWrite(ledPin, LOW);
          delay(j);
        }
        if(ledPin>12){
          LEDCounter*=-1;
          LEDSwitch=0;
          digitalWrite(13, LOW);
          delay(j);
        }
      }
    }
  }
}

void fastSlow(int Reps){
  for(int k=1; k<(Reps+1); k++){
    for(int j=1; j<257; j=j+j){
      int LEDCounter=1;
      for(int i=5; i>3 && i<14; i=i+LEDCounter){
        blink(i, j, 10); //Call the blink method below
        if(i>12){
          LEDCounter*=-1;
        }
      }
    }
  }
}


void blink(int LEDPin, int LEDOnTime, int LEDOffTime){
  digitalWrite(LEDPin, HIGH);
  delay(LEDOnTime);
  digitalWrite(LEDPin, LOW);
  delay(LEDOffTime);
}