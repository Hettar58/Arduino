const int inputVolt = 0;
const int led_v = 10;
const int led_j = 11;
const int led_r = 12;

const int r2 = 10000;
const int r1 = 220;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputVolt, INPUT);
  pinMode(led_v, OUTPUT);
  pinMode(led_r, OUTPUT);
  pinMode(led_j, OUTPUT);
  Serial.begin(9800);
}

void loop() {
  // put your main code here, to run repeatedly:
  float U = analogRead(inputVolt);
  U = U * 5.0 / 1024.0;

  if (U >= 0){
    digitalWrite(led_r, HIGH);
  }
  else{
    digitalWrite(led_r, LOW);
  }
  
  if (U >= 3){
    digitalWrite(led_j, HIGH);
  }
  else{
    digitalWrite(led_j, LOW);
  }
  
  if (U >= 4){
    digitalWrite(led_v, HIGH);
  }
  else{
    digitalWrite(led_v, LOW);
  }

  Serial.println(U);
  delay(100);
}
