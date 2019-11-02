const int inputVolt = 0;


float vOut = 0.0;
float vIn = 0.0;

float r1 = 220.0;
float r2 = 1000.0;

int value = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(inputVolt, INPUT);
  Serial.begin(9800);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(inputVolt);

  vOut = (value * 5.0) / 1024.0;

  vIn = vOut / (r2 / (r1 + r2));

  if (vIn < 0.13){
    vIn = 0.0;
  }

  Serial.print(vIn);
  Serial.println(" Volts");
  delay(500);
}
