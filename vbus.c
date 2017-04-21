// vbus.c
//
// (c) Hewell Technology Ltd. 2014
//
//****************************************************************************

#include "vbus.h"

unsigned char vbus_calc_crc(const unsigned char *buffer, int offset, int length)
{
    unsigned char crc = 0x7F;

    for (int idx = 0; idx < length; idx++)
    {
        crc = (crc - buffer [offset + idx]) & 0x7F;
    }

    return crc;
}

void vbus_extract_septett(unsigned char *buffer, int offset, int length)
{
    unsigned char septett = 0;

    for (int idx = 0; idx < length; idx++)
    {
        if (buffer[offset + idx] & 0x80)
        {
            buffer[offset + idx] &= 0x7F;
            septett |= (1 << idx);
        }
    }

    buffer [offset + length] = septett;
}

void vbus_inject_septett(unsigned char *buffer, int offset, int length)
{
    unsigned char septett = buffer[offset + length];

    for (int idx = 0; idx < length; idx++)
    {
        if (septett & (1 << idx))
        {
            buffer[offset + idx] |= 0x80;
        }
    }
}
