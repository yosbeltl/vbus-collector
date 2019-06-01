#ifndef DATATYPES_H
#define DATATYPES_H

#pragma pack(1)
typedef union {
  struct {
    unsigned long SystemData;
    short TempSensor1;
    short TempSensor2;
    short TempSensor3;
    short TempSensor4;
    unsigned short Day;
    unsigned long FlowV40;
    unsigned char SpeedRelay1;
    unsigned char SpeedRelay2;
    unsigned char SpeedRelay4;
    unsigned long HeatQuantity;
    unsigned short Version;
    unsigned long OperatingHoursRelay1;
    unsigned long OperatingHoursRelay2;
    unsigned long OperatingHoursRelay4;
    unsigned char HolidayFunction;    
    unsigned char BlockingProtection1;
    unsigned char BlockingProtection2;
    unsigned char BlockingProtection3;    
    unsigned short Initializing;
    unsigned long Filling;
    unsigned long Stabilizing;
    unsigned char PumpDelay;
    unsigned char HeatDump;
    unsigned char Trailing;       
    unsigned char ThermalDisinfection;
    unsigned char MemoryCooling;
    unsigned char CoolingSystem;
    unsigned char Spread;
    unsigned char AntiFreeze;
    unsigned char CollectorCooling;
    unsigned char MaximumStoreTemperature;
    unsigned char Reboots;
    unsigned char SensorError;
    unsigned char ErrorMask;
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
