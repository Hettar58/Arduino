const int led = 11;
int i = 0;
int mod = 1;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9800);
}

void loop() {
  if (i == 0){
    mod = 1;
  }
  else if(i == 255){
    mod = -1;
  }
  analogWrite(led, i);
  i += mod;
  Serial.println(i);
  delay(50);
}
