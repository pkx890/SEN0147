/* 
 * @file getVal.ino
 * @You can see the print on the serial port by filling in the parameter with the value of the register you want to get
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author      [PengKaixing](kaixing.peng@dfrobot.com)
 * @version  V2.0
 * @date  2020-5-21
 * @get from https://www.dfrobot.com
 * @get from https://www.dfrobot.com.cn
 */
#include "SEN0147.h"

/*
 * Initial default IIC address is 0x08
 */
#define IICaddr 0x08

SEN0147_IIC mySEN(IICaddr);
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("IICaddr==0x");  
  Serial.println(mySEN.getIICaddr(),HEX);
  delay(1000); 
  
  Serial.print("VID==0x");  
  Serial.println(mySEN.getVID(),HEX);
  delay(1000); 

  Serial.print("Gears==0x");  
  Serial.println(mySEN.getGears(),HEX);
  delay(1000); 

  Serial.print("Mode==0x");  
  Serial.println(mySEN.getMode(),HEX);
  delay(1000); 

  Serial.print("Light==0x");  
  Serial.println(mySEN.getLight(),HEX);
  delay(1000); 

  Serial.print("Black==0x");  
  Serial.println(mySEN.getBlack(),HEX);
  delay(1000); 

  Serial.print("Thres==0x");  
  Serial.println(mySEN.getThres(),HEX);
  delay(1000); 

  Serial.print("Outpolar==0x");  
  Serial.println(mySEN.getOutpolar(),HEX);
  delay(1000); 

  Serial.print("LEDpolar==0x");  
  Serial.println(mySEN.getLEDpolar(),HEX);
  delay(1000);   
}