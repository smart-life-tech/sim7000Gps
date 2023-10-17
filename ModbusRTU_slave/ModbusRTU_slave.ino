#include "ModbusRTU.h"

ModbusRTU::ModbusRTUSlave<16> slave;

unsigned short encoder = 0;
unsigned short analogOut[3];
bool digitalOut[4];
bool digitalIn[6];
unsigned short analogIn[2];

void setup()
{
  slave.begin(115200, &Serial2, 1);

  pinMode(A0, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT_PULLUP);
  pinMode(A7, INPUT_PULLUP);

  slave.update();

  slave.addCoil(&digitalOut[0], 0x0000);
  slave.addCoil(&digitalOut[1], 0x0001);
  slave.addCoil(&digitalOut[2], 0x0002);
  slave.addCoil(&digitalOut[3], 0x0003);

  slave.addDiscreteInput(&digitalIn[0], 0x1000);
  slave.addDiscreteInput(&digitalIn[1], 0x1001);
  slave.addDiscreteInput(&digitalIn[2], 0x1002);
  slave.addDiscreteInput(&digitalIn[3], 0x1003);
  slave.addDiscreteInput(&digitalIn[4], 0x1004);
  slave.addDiscreteInput(&digitalIn[5], 0x1005);

  slave.addInputRegister(&analogIn[0], 0x2000);
  slave.addInputRegister(&analogIn[1], 0x2001);

  slave.addHoldingRegister(&analogOut[0], 0x3000);
  slave.addHoldingRegister(&analogOut[1], 0x3001);
  slave.addHoldingRegister(&analogOut[2], 0x3002);
}

void loop()
{

  slave.update();
  Serial.println("data read from address1 :");
  Serial.println(analogOut[0]);
  Serial.println("data read from address2: ");
  Serial.println(analogOut[1]);
  Serial.println("data read from address3: ");
  Serial.println(analogOut[2]);
  delay(1000);
}
