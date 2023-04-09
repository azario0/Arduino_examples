void setup() {
    // Réglage du port numérique associé à la LED : mode sortie = OUTPUT
    pinMode(8, OUTPUT);
   }

void loop() {
   digitalWrite(8, HIGH); // Allumage de la LED : état haut = HIGH
   delay(1000);
   digitalWrite(8, LOW);  // Extinction de la LED : état bas = LOW
   delay(1000);
}