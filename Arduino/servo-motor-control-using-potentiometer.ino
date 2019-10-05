
Servo servoa;  

int potpin1 = 0;  
int val1;   


void setup() 
{ 
  servoa.attach(9);  
 
} 

void loop() 
{ 
  val1 = analogRead(potpin1);            
  val1 = map(val1, 0, 1023, 0, 179);      
  servoa.write(val1);                  
  delay(15);         

 
             }
