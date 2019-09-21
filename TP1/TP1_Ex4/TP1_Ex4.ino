const int LED_ROUGE = 12;
const int LED_ORANGE = 11;
const int LED_VERT = 10;
const int LED_P_ROUGE = 8;
const int LED_P_VERT = 9;
const int SWITCH = 3;

volatile int redDelay;
volatile int greenDelay;

void setup() {
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_VERT, OUTPUT);

  pinMode(LED_P_ROUGE, OUTPUT);
  pinMode(LED_P_VERT, OUTPUT);

  pinMode(SWITCH, INPUT);
  attachInterrupt(digitalPinToInterrupt(SWITCH), switchTrigger, RISING);
}

void loop() {
  greenDelay = 3000;
  redDelay = 3000;
    
  digitalWrite(LED_VERT, HIGH);
  digitalWrite(LED_P_ROUGE, HIGH);
  delay(greenDelay);
  digitalWrite(LED_VERT, LOW);
  
  digitalWrite(LED_ORANGE, HIGH);
  delay(1000);
  digitalWrite(LED_ORANGE, LOW);
  digitalWrite(LED_P_ROUGE, LOW);
  
  digitalWrite(LED_ROUGE, HIGH);
  digitalWrite(LED_P_VERT, HIGH);
  delay(redDelay);
  digitalWrite(LED_ROUGE, LOW);
  digitalWrite(LED_P_VERT, LOW);  
}

void switchTrigger(){
  greenDelay = 0;
  redDelay = 5000;
}
