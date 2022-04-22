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
#ifndef FORCE_H
#define FORCE_H

/*
 * Function to initialize the I2C module and register the slave address
 * @prereq I2C has already been initialized --done in IR init
 */
void forceInit(void);

/*
 * Function to wait for gesture. 
 * @return 1 if gesture was detected, 0 if no gesture or error
 */
int waitForGesture(void);

#endif
