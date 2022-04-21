#include "FSM.h"

void initFSM(){
    
}

FSMState nextStateFunction(FSMState currentState){
    FSMState nextState;
    switch(currentState){
        case wait:
            if(imuFlag){
                nextState = activate;
            }
            else{
                nextState = wait;
            }
        break;
        case activate:
            //TODO add function to poll temperature
            bool temperature = 0;
            if(temperature < 100){
                nextState = tooCold;
            }
            else if(temperature <= 120 && temperature >= 100){
                nextState = justRight;
            }
            else if(temperature > 120){
                nextState = tooHot;
            }
            else{ //an error occured
                nextState = error;
            }
            break;
        case tooCold:
            nextState = wait;
            break;
        case tooHot:
            nextState = wait;
            break;
        case justRight:
            nextState = wait;
            break;
        case error:
            nextState = wait;
            break;
    }
    return nextState;
}

void outputStateFunction(FSMState currentState){
    switch (currentState)
    {
    case wait:
        //TODO add code to check IMU and set flag
        break;
    case activate:
        int data = readTo();
        temperature = handleTo(data);
        break;
    case tooCold:
        pulseCold();
        break;
    case tooHot:
        pulseHot();
        break;
    case justRight:
        pulseRight();
        break;
    case error:
        pulseError();
        break;
    }
}
