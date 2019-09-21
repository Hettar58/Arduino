bool continuer = true;
const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (continuer){
    digitalWrite(LED, HIGH);
    delay(4000);
    digitalWrite(LED, LOW);
    delay(2000);
    digitalWrite(LED, HIGH);
    delay(8000);
    digitalWrite(LED, LOW);
    continuer = false;
  }
}
