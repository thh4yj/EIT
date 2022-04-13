#ifndef HAPTICS_H
#define HAPTICS_H

/*
 * Array to hold the pin numbers of the two haptic feedback modules used for the project
 */
int haptics[2];
int base = 0; //base index of array

/*
 * Set the pin as an output for haptic feedback and add to haptics array.
 * @prereq A PWM enabled pin MUST be used
 * @param pinNum the pin number to set as an output
 * @return void
 */
void setPinAsHaptic(int pinNum);
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






#endif
