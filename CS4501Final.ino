/*
 * Team 5 Final project code
 * Spring 2022
 * CS 4501
 */
#include "haptics.h"
#include "IR.h"
#include "Arduino.h"


void setup() {
  // put your setup code here, to run once:
  setPinAsHaptic(11);
  setPinAsHaptic(10);
  initIR();

}

void loop() {
  
}
