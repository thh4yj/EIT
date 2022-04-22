/*
 * Team 5 Final project code
 * Spring 2022
 * CS 4501
 */
 /*
  * ===================================================================================
                                      
                  ______          _            _   _        _____  
                  |  ___|        | |          | | (_)      |  ___| 
                  | |_ __ _ _ __ | |_ __ _ ___| |_ _  ___  |___ \  
                  |  _/ _` | '_ \| __/ _` / __| __| |/ __|     \ \ 
                  | || (_| | | | | || (_| \__ \ |_| | (__  /\__/ / 
                  \_| \__,_|_| |_|\__\__,_|___/\__|_|\___| \____/  
                                                                   
                                                 

  * ===================================================================================
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
  Serial.begin(9600);
  //testHaptics();
}

void loop() {
  state = nextStateFunction(state);
  outputStateFunction(state);
  Serial.println(state);
}
