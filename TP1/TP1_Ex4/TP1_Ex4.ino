const int LED_ROUGE = 12;
const int LED_ORANGE = 11;
const int LED_VERT = 10;
const int LED_P_ROUGE = 8;
const int LED_P_VERT = 9;
const int SWITCH = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_VERT, OUTPUT);

  pinMode(LED_P_ROUGE, OUTPUT);
  pinMode(LED_P_VERT, OUTPUT);

  pinMode(SWITCH, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LED_VERT, HIGH);
  delay(3000);
  digitalWrite(LED_VERT, LOW);
  
  digitalWrite(LED_ORANGE, HIGH);
  delay(1000);
  digitalWrite(LED_ORANGE, LOW);
  
  digitalWrite(LED_ROUGE, HIGH);
  int totalDelay = 0;
  while(digitalRead(SWITCH) == 0 || totalDelay < 3000){
    delay(50);
  }
  digitalWrite(LED_ROUGE, LOW);

  
}
