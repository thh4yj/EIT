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
    switch (currentState)
    {
    case wait:
        //TODO add code to check IMU and set flag
        imuFlag = 1;
        Serial.println("wait");
        break;
    case activate:
        int data = readTo();
        temperature = handleTo(data);
        Serial.println(temperature);
        break;
    case tooCold:
        Serial.println("Pulse cold");
        pulseCold();
        break;
    case tooHot:
        Serial.println("Pulse hot");
        pulseHot();
        break;
    case justRight:
        Serial.println("Pulse right");
        pulseRight();
        break;
    case error:
        Serial.println("Pulse error");
        pulseError();
        break;
    }
}
