int IRSENSOR = 5;
int LED=10;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(IRSENSOR,INPUT);
 
}

void loop() {
  int STATUSSENSOR=digitalRead(IRSENSOR);
  if(STATUSSENSOR==1)
  {
    digitalWrite(LED,LOW);
  }
  else
  {
    digitalWrite(LED,HIGH);
  }

}
