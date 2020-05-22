#include "SEN0147.h"
sRegister_t sRegister;

void SEN0147::getRegisterval(){
	readData(0x00);
	sRegister.IICAddresval = buf[0];
	sRegister.PIDval = buf[1];
	sRegister.VIDval = buf[2];
	sRegister.GEARSval = buf[3];
	sRegister.MODEval = buf[4];
	sRegister.Light_Hval = buf[5];
	sRegister.Light_Lval = buf[6];
	sRegister.Black_Hval = buf[7];
	sRegister.Black_Lval = buf[8];
	sRegister.Thres_Hval = buf[9];
	sRegister.Thres_Lval = buf[10];
	sRegister.Out_Polarval = buf[11];
	sRegister.LED_Polarval = buf[12];
}

void SEN0147::changeRegisterval(uint8_t Register,uint8_t data){
	writeData(Register,data);
}

uint8_t SEN0147::getIICaddr(){
	getRegisterval();
	return sRegister.IICAddresval;
}

void SEN0147::changeIICaddr(uint8_t newaddr){
	changeRegisterval(IICAddres,newaddr);
}

uint8_t SEN0147::getPID(){
	getRegisterval();
	return sRegister.PIDval;
}

uint8_t SEN0147::getVID(){
	getRegisterval();
	return sRegister.VIDval;
}

uint8_t SEN0147::getGears(){
	getRegisterval();
	return sRegister.GEARSval;
}

void SEN0147::changeGears(uint8_t newGears){
	changeRegisterval(GEARS,newGears);
}

uint8_t SEN0147::getMode(){
	getRegisterval();
	return sRegister.MODEval;
}

void SEN0147::changeMode(uint8_t newMode){
	changeRegisterval(MODE,newMode);
}

uint16_t SEN0147::getLight(){
	uint16_t LIGHT;
	getRegisterval();
	LIGHT=(sRegister.Light_Hval<<8) | (sRegister.Light_Lval);
	return LIGHT;
}

uint16_t SEN0147::getBlack(){
	uint16_t BLACK;
	getRegisterval();
	BLACK=(sRegister.Black_Hval<<8) | (sRegister.Black_Lval);
	return BLACK;
}

uint16_t SEN0147::getThres(){
	uint16_t THRES;
	getRegisterval();
	THRES=(sRegister.Thres_Hval<<8) | (sRegister.Thres_Lval);
	return THRES;
}

uint8_t SEN0147::getOutpolar(){
	getRegisterval();
	return sRegister.Out_Polarval;
}

void SEN0147::changeOutpolar(uint8_t newOutpolar){
	changeRegisterval(Out_Polar,newOutpolar);
}

uint8_t SEN0147::getLEDpolar(){
	getRegisterval();
	return sRegister.LED_Polarval;
}

void SEN0147::changeLEDpolar(uint8_t newLEDpolar){
	changeRegisterval(LED_Polar,newLEDpolar);
}

SEN0147_IIC::SEN0147_IIC(uint8_t addr){
	Wire.begin();
	this->IIC_addr=addr;
}

void SEN0147_IIC::writeData(uint8_t Reg,uint8_t Data){
	Serial.println("Reg==");Serial.println(Reg);
	Serial.println("Data==");Serial.println(Data);
   Wire.beginTransmission(this->IIC_addr);
   Wire.write(Reg);
   Wire.write(Data);
   Wire.endTransmission();
}

uint8_t SEN0147_IIC::readData(uint8_t Reg){
  int i=0;
  Wire.beginTransmission(this->IIC_addr);
  Wire.write(Reg);
  Wire.endTransmission();
  Wire.requestFrom(this->IIC_addr,13);
  while (Wire.available()){
	buf[i++]=Wire.read();
  }
}