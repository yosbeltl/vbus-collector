#ifndef DATATYPES_H
#define DATATYPES_H

#pragma pack(1)
typedef union {
  struct {
    unsigned short SystemData;
    short TempSensor1;
    short TempSensor2;
    short TempSensor3;
    short TempSensor4;
    unsigned char Day;
    unsigned char FlowV40;
    unsigned char SpeedRelay1;
    unsigned char SpeedRelay2;
    unsigned char SpeedRelay4;
    unsigned short HeatQuantityWH;
    unsigned short HeatQuantityKWH;
    unsigned short HeatQuantityMWH;
    unsigned short Version;
    unsigned short OperatingHoursRelay1;
    unsigned short OperatingHoursRelay2;
    unsigned short OperatingHoursRelay4;
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
  } bsPlusPkt;
  unsigned char asBytes[28];
} Data_Packet;

#endif
