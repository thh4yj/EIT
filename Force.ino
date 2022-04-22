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
   * Author: Thomas Forrester (tsf9nr)
   * Data: April 2022
   * Class: CS4501
   * Team: 5
   */
#include "Force.h"
#include "ICM_20948.h"

ICM_20948_I2C forceSensor;  // Initialize IMU object (force sensor)

const int numItems = 10;    // number of samples to average
float accX[numItems];       // Store the samples into an array
float accY[numItems];       // Store the samples into an array
float accZ[numItems];       // Store the samples into an array
int samp_index = 0;         // index to store a sample to the array
int activateIMU = 0;           // variable to keep track of if we want the device to read the temperature

void forceInit(){
  Wire.begin();
  //Wire.setClock(400000);
  forceSensor.begin(Wire, 1);
}
int waitForGesture(){
  
  // get the data from the IMU
  if (forceSensor.dataReady()) {
    forceSensor.getAGMT();

    float ax = forceSensor.accX();
    float ay = forceSensor.accY();
    float az = forceSensor.accZ();
    if(abs(ax) >= 1500 || abs(ay) >= 1500 || abs(az) >= 1500){
      return 1;
    }
    else{
      Serial.print("x : ");
      Serial.println(ax);
      Serial.print("y : ");
      Serial.println(ay);
      Serial.print("z : ");
      Serial.println(az);
      return 0;
    }
}
