#define r1 1
#define y1 2
#define g1 3

#define r2 4
#define y2 5
#define g2 6

#define r3 7
#define y3 8
#define g3 9

#define r4 10
#define y4 11
#define g4 12

int ledPins[] = { 1,2,3,4,5,6,7,8,9,10,11,12};
int pinCount = 12;
void setup()
{
for (int thisPin = 0; thisPin < pinCount; thisPin++) {
pinMode(ledPins[thisPin], OUTPUT);
}
}

void loop()
{
digitalWrite(r1, HIGH); +digitalWrite(r2, HIGH); digitalWrite(r3, HIGH); digitalWrite(r4, HIGH);
digitalWrite(y1, HIGH); digitalWrite(y2, HIGH); digitalWrite(y3, HIGH); digitalWrite(y4, HIGH);
digitalWrite(g1, HIGH); digitalWrite(g2, HIGH); digitalWrite(g3, HIGH); digitalWrite(g4, HIGH);
delay(4000);

digitalWrite(r1, HIGH); digitalWrite(r2, HIGH); digitalWrite(r3, HIGH); digitalWrite(r4, LOW);
digitalWrite(y1, LOW); digitalWrite(y2, LOW); digitalWrite(y3, LOW); digitalWrite(y4, LOW);
digitalWrite(g1, LOW); digitalWrite(g2,LOW); digitalWrite(g3, LOW); digitalWrite(g4, HIGH);
delay(4000);

digitalWrite(r1, HIGH); digitalWrite(r2, HIGH); digitalWrite(r3, LOW); digitalWrite(r4, LOW);
digitalWrite(y1, LOW); digitalWrite(y2, LOW); digitalWrite(y3, HIGH); digitalWrite(y4, HIGH);
digitalWrite(g1, LOW); digitalWrite(g2,LOW); digitalWrite(g3, LOW); digitalWrite(g4, LOW);
delay(4000);
digitalWrite(r1, HIGH); digitalWrite(r2, HIGH); digitalWrite(r3, LOW); digitalWrite(r4, HIGH);
digitalWrite(y1, LOW); digitalWrite(y2, LOW); digitalWrite(y3, LOW); digitalWrite(y4, LOW);
digitalWrite(g1, LOW); digitalWrite(g2,LOW); digitalWrite(g3, HIGH); digitalWrite(g4, LOW);
delay(4000);
digitalWrite(r1, HIGH); digitalWrite(r2, LOW); digitalWrite(r3, LOW); digitalWrite(r4, HIGH);
digitalWrite(y1, LOW); digitalWrite(y2, HIGH); digitalWrite(y3, HIGH); digitalWrite(y4, LOW);
digitalWrite(g1, LOW); digitalWrite(g2,LOW); digitalWrite(g3, LOW); digitalWrite(g4, LOW);

delay(4000);
digitalWrite(r1, HIGH); digitalWrite(r2, LOW); digitalWrite(r3, HIGH); digitalWrite(r4, HIGH);
digitalWrite(y1, LOW); digitalWrite(y2, LOW); digitalWrite(y3, LOW); digitalWrite(y4, LOW);
digitalWrite(g1, LOW); digitalWrite(g2,HIGH); digitalWrite(g3, LOW); digitalWrite(g4, LOW);

delay(4000);
digitalWrite(r1, LOW); digitalWrite(r2, LOW); digitalWrite(r3, HIGH); digitalWrite(r4, HIGH);
digitalWrite(y1, HIGH); digitalWrite(y2, HIGH); digitalWrite(y3, LOW); digitalWrite(y4, LOW);
digitalWrite(g1, LOW); digitalWrite(g2,LOW); digitalWrite(g3, LOW); digitalWrite(g4, LOW);
delay(4000);
digitalWrite(r1, LOW); digitalWrite(r2, HIGH); digitalWrite(r3, HIGH); digitalWrite(r4, HIGH);
digitalWrite(y1, LOW); digitalWrite(y2, LOW); digitalWrite(y3, LOW); digitalWrite(y4, LOW);
digitalWrite(g1, HIGH); digitalWrite(g2,LOW); digitalWrite(g3, LOW); digitalWrite(g4, LOW);
delay(4000);
digitalWrite(r1, LOW); digitalWrite(r2, HIGH); digitalWrite(r3, HIGH); digitalWrite(r4, LOW);
digitalWrite(y1, HIGH); digitalWrite(y2, LOW); digitalWrite(y3, LOW); digitalWrite(y4, HIGH);
digitalWrite(g1, LOW); digitalWrite(g2,LOW); digitalWrite(g3, LOW); digitalWrite(g4, LOW);
delay(4000);

}
