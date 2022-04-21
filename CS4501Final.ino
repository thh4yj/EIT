/*
 * Team 5 Final project code
 * Spring 2022
 * CS 4501
 */

// ********** Includes **********
#include "haptics.h"
#include "IR.h"
#include "FSM.h"
#include "Arduino.h"
//           ********************

// ********** Global Variables **********
  FSMState state = error; //initialize the FSM into a state that will immediatly send it into wait which will begin polling the IMU

//                             **********

void setup() {
  // put your setup code here, to run once:
  setPinAsHaptic(11);
  setPinAsHaptic(10);
  initIR();
  initFSM();
}

void loop() {
  state = nextStateFunction(state);
  outputStateFunction(state);
}
