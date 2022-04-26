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
#include "FSM.h"

void initFSM(){
    
}

#define minTemp 100
#define maxTemp 120
FSMState nextStateFunction(FSMState currentState){
    Serial.print("Current state: ");
    Serial.println(currentState);
    FSMState nextState = error;
    Serial.println("switch");
    if(currentState == wait){
        Serial.println("Wait state");
        if(imuFlag){
            nextState = activate;
        }
        else{
            nextState = wait;
        }
        imuFlag = 0;
    }
    else if(currentState ==  activate){
        Serial.println("Act state");
        if(temperature < minTemp){
            nextState = tooCold;
        }
        else if(temperature <= maxTemp && temperature >= minTemp){
            nextState = justRight;
        }
        else if(temperature > maxTemp){
            nextState = tooHot;
        }
        else{ //an error occured
            Serial.println("Changing state to error");
            nextState = error;
        }
    }
    else if(currentState ==  tooCold){
        Serial.println("cold state");
        nextState = wait;
    }
    else if(currentState ==  tooHot){
        Serial.println("hot state");
        nextState = wait;
    }
    else if(currentState ==  justRight){
        Serial.println("right state");
        nextState = wait;
    }
    else if(currentState ==  error){
        Serial.println("Next state wait from error!");
        nextState = wait;
    }
    else{
        Serial.println("Default reached, erro!");
    }
    Serial.print("Next state: ");
    Serial.println(nextState);
    return nextState;
}


void outputStateFunction(FSMState currentState){
    if(currentState == wait){
        //TODO add code to check IMU and set flag
        imuFlag = waitForGesture();
        //imuFlag = 1;
        Serial.println("wait");
    }
    else if(currentState == activate){
        pulseTemp();
        int data = readTo();
        temperature = handleTo(data);
        Serial.println(temperature);
    }
    else if(currentState == tooCold){
        Serial.println("Pulse cold");
        pulseCold();
    }
    else if(currentState == tooHot){
        Serial.println("Pulse hot");
        pulseHot();
    }
    else if(currentState == justRight){
        Serial.println("Pulse right");
        pulseRight();
    }
    else if(currentState == error){
        Serial.println("Pulse error");
        pulseError();
    }
}
