#ifndef FSM_H
#define FSM_H

#include "IR.h"
#include "haptics.h"

typedef enum {
  wait,
  activate,
  tooHot,
  tooCold,
  justRight,
  error
}FSMState;

double temperature;
int imuFlag;


/*
 * Function to initialize components of the FSM
 */
void initFSM();

/*
 * Function to choose the next state to enter based on conditions
 * @param the current state of the machine
 * @Return the next state to enter
 */
FSMState nextStateFunction(FSMState currentState);

/*
 * Function to perform the outputs of states based on the state taken in
 * @param the current state of the machine to output the current function
 * @return void
 */
void outputStateFunction(FSMState currentState);



#endif
