const int inputVolt = 0;

int r1=220; //première R connue

void setup() {
  // put your setup code here, to run once:
  pinMode(inputVolt, INPUT);
  Serial.begin(9800);
}

void loop() {
  // put your main code here, to run repeatedly:

  float U = analogRead(inputVolt);
  U = U * 5.0 / 1023;
  float r2 = (U*r1)/(5.0-U);

  Serial.println(r2);
  delay(1000);
}
