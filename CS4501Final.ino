//#include <haptics.h>
//#include "haptics.h"


/*
 * Array to hold the pin numbers of the two haptic feedback modules used for the project
 */
int haptics[2];

/*
 * Set the pin as an output for haptic feedback and add to haptics array.
 * @prereq A PWM enabled pin MUST be used
 * @param pinNum the pin number to set as an output
 * @return void
 */
void setPinAsHaptic(int);
/*
 * Pulse the pin for the given duration.
 * @prereq pinNum must be set as output pin
 * @param pinNum the pin to pulse
 * @param duration the time in microseconds to hold the pin high for
 * @return void
 */
void pulseHaptic(int pinNum, int duration);
/*
 * Pulse the haptic pins for the given duration.
 * @prereq haptics must be set as output pins
 * @param duration the time in microseconds to hold the pin high for
 * @return void
 */
void pulseHaptics(int duration);
/*
 * Pulse the haptic pins for the given duration.
 * @prereq haptics must be set as output pins
 * @param duration the time in microseconds to hold the pin high for
 * @param powerPCT the power percentage to pulse at
 * @return void
 */
void pulseHapticsPWM(int duration, int powerPCT);

//The next three functions require that two pins have been set up for the haptic feedback. 

/*
 * Perform the cold pulse to indicate too cold
 * @return void
 */
void pulseCold(void);
/*
 * Perform the hot pulse to indicate too hot.
 * @return void
 */
 void pulseHot(void);
 /*
  * Indicate the temperature is just right.
  * @return void
  */
 void pulseRight(void);

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



int index = 0; //base index of array


void setPinAsHaptic(int pinNum){
  if(index < 2){ //prevent array overflow
    pinMode(pinNum, OUTPUT); //set pin as output
    haptics[index] = pinNum; //add to haptic array
    index++; 
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

  float power = powerPCT/100.0 *255.0;
  //Serial.print("Power: ");
  //Serial.println(power);
  analogWrite(pin1, power);
  analogWrite(pin2, power);
  delay(duration); //hold for duration microseconds
  //then disable
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

#define coldPWM 60 //Percentage of power to vibrate at
#define coldDelay 1000
#define numPulses 5
void pulseCold(void){
  for(int i = 0; i < numPulses; i++){
    pulseHapticsPWM(coldDelay, coldPWM);
    delay(coldDelay);
  }
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
    delay(100);
  }
}

#define numNormPulses 2
#define normalPWM 85
#define normalDelay 800
void pulseRight(void){
  for(int i = 0; i < numNormPulses; i++){
    pulseHapticsPWM(normalDelay, normalPWM);
    delay(normalDelay);
  }
}
