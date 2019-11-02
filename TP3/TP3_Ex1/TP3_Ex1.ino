const int trigPin = 12;
const int echoPin = 13;
const int buzzer = 7;
const int bouton = 4;

long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9800);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (buzzer, OUTPUT);
  Serial.println("~~~ Debut programme ~~~");
}

void loop() {
  // Envoie de l'onde
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   // Réception de l'écho
   duration = pulseIn(echoPin, HIGH);
   // Calcul de la distance
   distance = (duration/2) / 29.1;
    if (distance >= 400 || distance <= 0){ Serial.println("Hors plage");
    }
    else {
    Serial.print("distance = "); Serial.print(distance); Serial.println(" cm");
    }
   delay(500); // délai entre deux mesures
}
