/* 
 * @file changeVal.ino
 * @Enter the address and value of the register you want to change
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
  mySEN.changeIICaddr(0x09);
  delay(3000);
  Serial.print("newaddr==0x");
  Serial.println(getIICaddr(),HEX);
  delay(1000);
  
  mySEN.changeGears(0x09);
  delay(3000);
  Serial.print("newGears==0x");
  Serial.println(getGears(),HEX);
  delay(1000);
  
  mySEN.changeMode(0x09);
  delay(3000);
  Serial.print("newaddr==0x");
  Serial.println(getMode(),HEX);
  delay(1000);
  
  mySEN.changeOutpolar(0x09);
  delay(3000);
  Serial.print("newaddr==0x");
  Serial.println(getOutpolar(),HEX);
  delay(1000);
  
  mySEN.changeLEDpolar(0x09);
  delay(3000);
  Serial.print("newaddr==0x");
  Serial.println(getLEDpolar(),HEX);
  delay(1000);  
}