#include "haptics.h"
#define OUTPUT 1
#define HIGH 1
#define LOW 0

int base = 0; //base index of array


void setPinAsHaptic(int pinNum){
  if(base < 2){ //prevent array overflow
    pinMode(pinNum, OUTPUT); //set pin as output
    haptics[base] = pinNum; //add to haptic array
    base++; 
  }
}

void pulseHaptic(int pinNum, int duration){
  digitalWrite(pinNum, HIGH);
  delay(duration);
  digitalWrite(pinNum, LOW);
}

void pulseHaptics(int duration){
  int pin1 = haptics[0];
  int pin2 = haptics[1];
  
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  delay(duration);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

void pulseHapticsPWM(int duration, int powerPCT){
  int pin1 = haptics[0];
  int pin2 = haptics[1];

  int power = powerPCT/100 *1024;
  analogWrite(pin1, power);
  analogWrite(pin2, power);
  delay(duration); //hold for duration microseconds
  //then disable
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

#define coldPWM 50 //Percentage of power to vibrate at
#define coldDelay 400
#define numPulses 4
void pulseCold(void){
  for(int i = 0; i < numPulses; i++){
    pulseHapticsPWM(coldDelay, coldPWM);
    delay(coldDelay);
  }
}

#define numHotPulses 7
void pulseHot(void){
  //perform numPulses number of rapid pulses
  for(int i = 0; i < numHotPulses; i++){
    pulseHaptics(150);
    delay(50);
  }
}

#define numNormPulses 1
#define normalPWM 85
#define normalDelay 1000
void pulseRight(void){
  for(int i = 0; i < numNormPulses; i++){
    pulseHapticsPWM(normalDelay, normalPWM);
    delay(normalDelay);
  }
}

void testHaptics(void){
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
