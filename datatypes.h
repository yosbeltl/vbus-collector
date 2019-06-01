#ifndef DATATYPES_H
#define DATATYPES_H

#pragma pack(1)
typedef union {
  struct {
    short SystemData1;
    short SystemData2;
    short TempSensor1;
    short TempSensor2;
    short TempSensor3;
    short TempSensor4;
    short Day;
    short FlowV40_1;
    short FlowV40_2;
    unsigned char SpeedRelay1;
    unsigned char SpeedRelay2;
    unsigned char SpeedRelay4;
    unsigned char PumpSpeed1;
    unsigned char PumpSpeed2;
    unsigned char RelayMask;
    unsigned char ErrorMask;
    unsigned short SystemTime;
    unsigned char Scheme;
    unsigned char OptionCollectorMax:1;
    unsigned char OptionCollectorMin:1;
    unsigned char OptionCollectorFrost:1;
    unsigned char OptionTubeCollector:1;
    unsigned char OptionRecooling:1;
    unsigned char OptionHQM:1;
    unsigned char rfu:2;
    unsigned short OperatingHoursRelay1;
    unsigned short OperatingHoursRelay2;
    unsigned short HeatQuantityWH;
    unsigned short HeatQuantityKWH;
    unsigned short HeatQuantityMWH;
    unsigned short Version;
  } bsPlusPkt;
  unsigned char asBytes[28];
} Data_Packet;

#endif
