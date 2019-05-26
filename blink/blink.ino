const int SLEEP = 1000;
const int LED = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  delay(SLEEP);
  digitalWrite(LED, LOW);
  delay(SLEEP);
}
