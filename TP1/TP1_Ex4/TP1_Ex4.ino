const int LED_ROUGE = 12;
const int LED_ORANGE = 11;
const int LED_VERT = 10;
const int LED_P_ROUGE = 8;
const int LED_P_VERT = 9;
const int SWITCH = 3;

int redDelay = 3000;
int greenDelay = 3000;
bool swState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_VERT, OUTPUT);

  pinMode(LED_P_ROUGE, OUTPUT);
  pinMode(LED_P_VERT, OUTPUT);

  pinMode(SWITCH, INPUT);
}

void loop() {

  redDelay = 3000;
  //greenDelay = 3000;

  digitalWrite(LED_VERT, HIGH);
  digitalWrite(LED_P_ROUGE, HIGH);
  int totalDelay = 0;
  do{
    delay(50);
    if (digitalRead(SWITCH == HIGH)){
      redDelay = 5000;
    }
    totalDelay += 50;
  }
  while (digitalRead(SWITCH) == LOW && totalDelay < 3000);
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
