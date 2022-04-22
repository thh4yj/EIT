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

    if (samp_index < numItems - 1)
      samp_index ++;
    else
      samp_index = 0;

    accX[samp_index] = ax;               // add the force sensor reading to the array

    float xSum = 0;
    for (int i = 0; i < numItems; i++)   // loop through and calculate the sum of the data gathered
    {
      xSum += accX[i];
    }
    float xAvg = xSum / numItems; // calculate the average
    Serial.print(xAvg);

    // If the user shakes the wand, call function to read the temperature data
    if (abs(xAvg) >= 1850) {
      if (activateIMU == 0) {
        activateIMU = 1;
        return activateIMU;
        //call function here
        activateIMU = 0;
      }
    }
    delay(10);
  }
  return 0;
}
