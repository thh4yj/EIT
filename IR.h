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

#ifndef IR_H
#define IR_H
/*
 * Code adapted from 5 Guys 1 Capstone project which also used a MLX90614 type IR sensor.
 */

#include <Wire.h>

int address = 0x5A; //address of IR sensor

#define WRITE 0
#define READ 1
int readCode = 0x07; //command to read, found in Melexis data sheet
int data = 9;

int TaAddress = 0x06; //register address for Ta
int ToAddress = 0x07; //register address for To
int Ta; //ambient temp
int To; //object temp

/*
 * Convert Ta into a temperature from byte values
 * @param data is the byte data from the sensor
 * @return double containing the value of the register
 */
double convertTa(int data);

/*
 * Convert the temperature of the byte data to degrees F
 * @param data is the bytes from the sensor
 * @return double containing the degrees F that the sensor read
 */
double handleTo(int data);

/*
 * Read the ambient temp from the sensor
 * @return byte data from the sensor
 */
int readTa(void);

/*
 * Read the object temp from the sensor
 * @return value byte data from the sensor
 */
int readTo(void);

/*
 * Initialize wire and vars for IR sensor readings
 */
void initIR(void);




#endif
