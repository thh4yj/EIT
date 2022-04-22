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
  /*
   * Author: Tyler Hendricks (thh4yj)
   * Data: April 2022
   * Class: CS4501
   * Team: 5
   */
#ifndef FSM_H
#define FSM_H

#include "IR.h"
#include "haptics.h"

typedef enum {
  wait,     //0
  activate, //1
  tooHot,   //2
  tooCold,  //3
  justRight,//4
  error     //5
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
