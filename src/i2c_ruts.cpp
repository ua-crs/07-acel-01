/*
 *  i2c_ruts.cpp
 */

#include <Arduino.h>
#include <Wire.h>

#include "i2c_ruts.h"

/*
 *  i2c_write:
 *      i2c command write to register address
 */
void
i2c_write(int i2c_address, uint8_t regAddress, uint8_t data)
{
    Wire.beginTransmission(i2c_address);
    Wire.write(regAddress);
    Wire.write(data);
    Wire.endTransmission();
}

/*
 *  i2c_reqdata:
 *      Request consecutive data 
 */
void
i2c_reqdata(int i2c_address,int reg, int byte_size)
{
    Wire.beginTransmission(i2c_address);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(i2c_address, byte_size );
    while( Wire.available() != byte_size )
    ;
}

/*
 *  i2c_get2asint
 *      gets next two bytes and return a 16 bit int
 */

short
i2c_get2asint( void )
{
    return (((short)Wire.read() << 8) | Wire.read());
}




