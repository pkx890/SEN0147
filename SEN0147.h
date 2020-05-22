#include <Arduino.h>
#include <Wire.h>

#define IICAddres 0x00
#define PID 0x01
#define VID 0x02
#define GEARS 0x03
#define MODE 0x04
#define Light_H 0x05
#define Light_L 0x06
#define Black_H 0x07
#define Black_L 0x08
#define Thres_H 0x09
#define Thres_L 0x0A
#define Out_Polar 0x0B
#define LED_Polar 0x0C

typedef struct{
	uint8_t IICAddresval;
	uint8_t PIDval;
	uint8_t VIDval;
	uint8_t GEARSval;
	uint8_t MODEval;
	uint8_t Light_Hval;
	uint8_t Light_Lval;
	uint8_t Black_Hval;
	uint8_t Black_Lval;
	uint8_t Thres_Hval;
	uint8_t Thres_Lval;
	uint8_t Out_Polarval;
	uint8_t LED_Polarval;
} sRegister_t;
extern sRegister_t sRegister;

class SEN0147 {
  public:
    SEN0147(){};
    ~SEN0147(){};
	virtual void writeData(uint8_t Reg,uint8_t Data)=0;
	virtual uint8_t readData(uint8_t Reg)=0;
	void getRegisterval();
	void changeRegisterval(uint8_t Register,uint8_t data);
	uint8_t getIICaddr();
	void changeIICaddr(uint8_t newaddr);
	uint8_t getPID();
	uint8_t getVID();
	uint8_t getGears();
	void changeGears(uint8_t newGears);
	uint8_t getMode();
	void changeMode(uint8_t newMode);
	uint16_t getLight();
	uint16_t getBlack();
	uint16_t getThres();
	uint8_t getOutpolar();
	void changeOutpolar(uint8_t newOutpolar);
	uint8_t getLEDpolar();
	void changeLEDpolar(uint8_t newLEDpolar);
	uint8_t buf[13]={0};
  private:
	
};

class SEN0147_IIC : public SEN0147{
  public:
    SEN0147_IIC(uint8_t addr);
    ~SEN0147_IIC(){};
	void writeData(uint8_t Reg,uint8_t Data);
	uint8_t readData(uint8_t Reg);
  private:
    uint8_t IIC_addr;
};