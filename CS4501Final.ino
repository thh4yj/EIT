#include "haptics.h"
#include "Arduino.h"


void setup() {
  // put your setup code here, to run once:
  setPinAsHaptic(11);
  setPinAsHaptic(10);

  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  Serial.println("Cold");
  pulseCold();
  digitalWrite(13, LOW);
  delay(2000);
    digitalWrite(13, HIGH);
      Serial.println("Hot");
  pulseHot();
    digitalWrite(13, LOW);
  delay(2000);
    digitalWrite(13, HIGH);
      Serial.println("Right");
  pulseRight();
  digitalWrite(13, LOW);
  delay(2000);
}
