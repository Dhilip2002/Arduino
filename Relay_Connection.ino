int RELAY=13
void setup() {
  pinMode(RELAY,OUTPUT);

}

void loop() {
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(2000);

}
