int analogVoltage=A0;
void setup() {
  pinMode(analogVoltage,INPUT);
  Serial.begin(9600);

}

void loop() {
  int step=analogRead(A0);
  float temp=step*0.48828125;
  Serial.print("Room Temperature=");
  Serial.print(temp);
  Serial.println("°C");
  delay(2000);

}
