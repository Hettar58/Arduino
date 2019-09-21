const int LED_ROUGE = 12;
const int LED_ORANGE = 11;
const int LED_VERT = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_VERT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_ORANGE, HIGH);
  delay(1000);
  digitalWrite(LED_ORANGE, LOW);
  
  digitalWrite(LED_ROUGE, HIGH);
  delay(3000);
  digitalWrite(LED_ROUGE, LOW);

  digitalWrite(LED_VERT, HIGH);
  delay(3000);
  digitalWrite(LED_VERT, LOW);
}
