int RED=11;
int ORANGE=12;
int GREEN=13;
void setup() {
  pinMode(RED,OUTPUT);
  pinMode(ORANGE,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
  digitalWrite(RED,HIGH);
  digitalWrite(ORANGE,LOW);
  digitalWrite(GREEN,LOW);
  delay(1000);
  
  digitalWrite(RED,HIGH);
  digitalWrite(ORANGE,HIGH);
  digitalWrite(GREEN,LOW);
  delay(1000);
  
  digitalWrite(RED,LOW);
  digitalWrite(ORANGE,LOW);
  digitalWrite(GREEN,HIGH);
  delay(1000);
  
  digitalWrite(RED,LOW);
  digitalWrite(ORANGE,HIGH);
  digitalWrite(GREEN,HIGH);
  delay(1000);
}
