#include <LiquidCrystal.h>

const int contraste = 6; //pin de réglage de contraste
const int led1 = 10;
const int led2 = 9;
const int led3 = 8;
const int swRead1 = 2; //analog 2
const int swRead2 = 1; //analog 1
const int swRead3 = 0; //analog 0

bool sw1Checked = false;
bool sw2Checked = false;
bool sw3Checked = false;

int sw1Value = 0;
int sw2Value = 0;
int sw3Value = 0;

bool blinkLED = false;
int mode = 0;

int essais = 3;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(contraste, OUTPUT);
  pinMode(swRead1, INPUT);
  pinMode(swRead2, INPUT);
  pinMode(swRead3, INPUT);

  analogWrite(contraste, 100);
  lcd.begin(16, 2);
}

void loop() {
  if (analogRead(swRead1) == 5 && sw1Checked == false){
    tirage(1);
    sw1Checked = true;
  }

  if (analogRead(swRead2) == 5 && sw2Checked == false){
    tirage(2);
    sw2Checked = true;
  }

  if (analogRead(swRead3) == 5 && sw3Checked == false){
    tirage(3);
    sw3Checked = true;
  }

  checkWin();
  checkBlink(mode);
}

void tirage(int pos){
    if (pos == 1){
      sw1Value = random(1, 9);
      lcd.setCursor(0, 4);
      lcd.print(sw1Value);
    }

    if (pos == 2){
      sw2Value = random(1, 9);
      lcd.setCursor(0, 8);
      lcd.print(sw2Value);
    }

    if (pos == 3){
      sw3Value = random(1, 9);
      lcd.setCursor(0, 12);
      lcd.print(sw3Value);
    }
}

void checkWin(){
  if (sw1Value != 0 && sw2Value != 0 && sw3Value != 0){
      if((sw1Value == sw2Value) && sw1Value == sw3Value){
          lcd.setCursor(0, 1);
          lcd.print("WIN !!");
          blinkLED = true;
          mode = 0; //mode clignottement
          
      }
      else{
        if (essais != 0){
          essais--;
          reset();
        }
        else{
          lcd.setCursor(0, 1);
          lcd.print("GAME OVER");
          blinkLED = true;
          mode = 1; //mode constant
        }
      }
  }
}

void checkBlink(int mode){
  if (blinkLED == true){
    if (mode == 0){
      int totalTime = 0;
      while (totalTime < 20000){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        delay(100);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        totalTime += 100;
      }
    }
    else if (mode == 1){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }
    reset();
  }
}

void reset(){
    sw1Checked = false;
    sw2Checked = false;
    sw3Checked = false;

    sw1Value = 0;
    sw2Value = 0;
    sw3Value = 0;

    blinkLED = false;
    mode = 0;

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
}
