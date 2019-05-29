int facteur1= 0;
int facteur2 = 7;
boolean continuer = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("###= Communication initialisée =###");
  Serial.println("Table de multiplication");
  Serial.print("Table de: ");
  Serial.println(facteur2);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (continuer){
    Serial.print(facteur1);
    Serial.print(" x ");
    Serial.print(facteur2);
    Serial.print(" = ");
    Serial.print(facteur1 * facteur2);
    Serial.println();
    if (facteur1 < 14){
      facteur1++;
      continuer = true;
    }else{
      continuer = false;
    }
  }
}
