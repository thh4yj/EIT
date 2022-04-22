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
#include "IR.h"


void initIR(){
  Wire.begin();
  delay(100);
  Ta = -255;
  To = -255;
}


int readTa(){
  Wire.beginTransmission(address);
  Wire.write(TaAddress);
  Wire.endTransmission(false);
  Wire.requestFrom(address, 3);
  int low, high;
  int result;
  low = Wire.read();
  high = Wire.read();
  result = low + (high << 8);
  byte PEC = Wire.read();
  return result;
}

int readTo(){
  Wire.beginTransmission(address);
  Wire.write(ToAddress);
  Wire.endTransmission(false);
  Wire.requestFrom(address, 3);
  int low, high;
  int result;
  low = Wire.read();
  high = Wire.read();
  result = low + (high << 8);
  byte PEC = Wire.read();
  return result;
}

double convertTa(int data){
  return data * 0.02;
}

double handleTo(int data){
  if(data & 0x8000){
    return -255;
  }

  double output = data / 50.0;
  //K to F
  output = (output - 273.15) * 9.0/5.0 + 32;
  return output;
}
