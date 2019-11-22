#include <LiquidCrystal.h>
#include <Servo.h>
//servo cablé sur PWM
//buzzer cablé sur PWM
//buzzer prend une résistance de 220
//lcd prend une R de 220
//2 derniers pins du LCD cablés en +1
const int trigPin = 10;
const int echoPin = 8;
const int buzzer = 9;
const int LED1 = 0;
const int LED2 = 0;
const int LED3 = 0;
const int contraste = 6;
const int serv = 11;

LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
Servo servomoteur;

long duration;
long distance;

void setup() {
  Serial.begin(9800);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (buzzer, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(contraste, OUTPUT);
  
  Serial.println("### Debut programme ###");
  analogWrite(6, 100);
  lcd.begin(16, 2);
  servomoteur.attach(serv);
}

void loop() {
  // Envoi de l'onde
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   // Réception de l'écho
   duration = pulseIn(echoPin, HIGH);
   
   // Calcul de la distance
   distance = (duration/2) / 29.1;
    if (distance >= 400 || distance <= 0){ 
      Serial.println("Hors plage");
      lcd.setCursor(0, 1);
      lcd.print("Hors plage");
    }
    else {
      Serial.print("distance = "); Serial.print(distance); Serial.println(" cm");
      lcd.setCursor(0, 1);
      lcd.print("distance = "); lcd.print(distance); lcd.print(" cm");
    }
    updateLED();
    updateServo();
    updateBuzzer();
   delay(2000); // délai entre deux mesures
}

void updateLED(){
  if (distance <= 5){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
  }
  else if (distance > 5 && distance <= 15){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
  }
  else if(distance > 15){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }
}

void updateServo(){
  if (distance <= 5){
    servomoteur.write(30);
  }
  else if (distance > 5 && distance <= 15){
    servomoteur.write(90);
  }
  else if (distance > 15){
    servomoteur.write(120);
  }
}

void updateBuzzer(){
  if (distance <= 5){
    //igitalWrite(buzzer, HIGH);
    tone(buzzer, 1000);
  }
  else{
    //digitalWrite(buzzer, LOW);
    noTone(buzzer);
  }
}
