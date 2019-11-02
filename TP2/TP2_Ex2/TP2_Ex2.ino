#include <LiquidCrystal.h>

const int inputVolt = 0;
const int led_v = 7;
const int led_j = 8;
const int led_r = 9;
const int contraste = 6;

LiquidCrystal ecran(12, 11, 5, 4, 3, 2);
void setup() {
  pinMode(inputVolt, INPUT);
  pinMode(led_v, OUTPUT);
  pinMode(led_r, OUTPUT);
  pinMode(led_j, OUTPUT);
  pinMode(contraste, OUTPUT);
  analogWrite(contraste, 100);
  ecran.begin(16, 2);
  ecran.print("Tension actuelle");
}

void loop() {
  float U = analogRead(inputVolt);
  U = U * 5.0 / 1023.0;

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
  ecran.setCursor(0, 1);
  ecran.print(U);
  ecran.print(" Volts");
}
