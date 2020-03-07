/*
 *  i2c_ruts.h
 *      i2c related routines
 */

#include <Arduino.h>

/*
 *  i2c_write:
 *      i2c command write to register address
 */
void i2c_write(int i2c_address, uint8_t regAddress, uint8_t cmd);

/*
 *  i2c_reqdata:
 *      Request consecutive bytes 
 */
void i2c_reqdata(int i2c_address,int reg, int byte_size);

/*
 *  i2c_get2asint
 *      gets next two bytes and return a 16 bit int
 */

short i2c_get2asint( void );


