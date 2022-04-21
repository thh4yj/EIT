#include "ICM_20948.h"

ICM_20948_I2C forceSensor;  // Initialize IMU object (force sensor)

const int numItems = 10;    // number of samples to average
float accX[numItems];       // Store the samples into an array
int samp_index = 0;         // index to store a sample to the array
int activate = 0;           // variable to keep track of if we want the device to read the temperature

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(400000);
  forceSensor.begin(Wire, 1);
}

void loop() {
  
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

    if (abs(xAvg) >= 1850) {
      if (activate == 0) {
        activate = 1;
        //call function here
        activate = 0;
      }
    }
    delay(10);
  }
}
