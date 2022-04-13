#include "haptics.h"


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

#define coldPWM 30 //Percentage of power to vibrate at
#define coldDelay 1000
void pulseCold(void){
  pulseHapticsPWM(coldDelay, coldPWM);
//  int pin1 = haptics[0];
//  int pin2 = haptics[1];
//
//  int power = coldPWM/100 *1024;
//  analogWrite(pin1, power);
//  analogWrite(pin2, power);
//  delay(1000); //hold for 1 second
//  //then disable
//  digitalWrite(pin1, LOW);
//  digitalWrite(pin2, LOW);
}

#define numHotPulses 4
void pulseHot(void){
  //perform numPulses number of rapid pulses
  for(int i = 0; i < numHotPulses; i++){
    pulseHaptics(100);
  }
}

#define numNormPulses 2
#define normalPWM 75
#define normalDelay 200
void pulseRight(void){
  for(int i = 0; i < numNormPulses; i++){
    pulseHapticsPWM(normalDelay, normalPWM);
  }
}
