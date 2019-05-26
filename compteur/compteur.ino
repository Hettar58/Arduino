int cpt = 0;
int iMax = 1;
int sleep = 500;
const int LED = 13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("###= Communication initialisée =###");
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (cpt <= 20){
    Serial.println(cpt);
    if (cpt == 20){
      Serial.println("###= Done ! =###");
    }
    for (int i = 1; i <= iMax; i++){
      digitalWrite(LED, HIGH);
      delay(sleep/iMax);
      digitalWrite(LED, LOW);
      delay(sleep/iMax);
    }
    if (cpt >= 1){
      iMax = 2;
    }
    cpt++;
  }
  
}
