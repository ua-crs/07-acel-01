/*
 *     Project 07-acel - Main file
 *         Manejo del acelerometro MPU6050
 *         Usa interfase i2c
 *         Detalle ver hoja de datos del circuito integrado
 *
 *         Version 01: separado en modulos de abstraccion
 */

#include <Arduino.h>
#include <Wire.h>

#include "mpu6050.h"

/*
 *  Constantes definidas en platformio.ini
 *      SERIAL_BAUD     baud rate del monitor
 *      MPU6050_ADDRESS direccion i2c del MPU6050
 *      SDA_PIN         IOPort de i2c Data
 *      SCL_PIN         IOPort de i2c Clock
 */

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    Serial.println();
    Serial.println("Serial ready");

    Wire.begin(SDA_PIN, SCL_PIN); // Inicializacion de I2C
    delay(150);

    Serial.println("mpu650_init");
    mpu6050_init(MPU6050_ADDRESS);       //    Inicializacion del chip
}

void
loop(void)
{
    unsigned i;
    double *pval;

    pval = mpu6050_values();                            //  Obtener valores a traves de puntero
    for( i = 0; i < MPU_ITEMS; ++i )
        Serial.printf( "**: %7.3f\t", *pval++ );        //  Imprimir valores
    Serial.println();
    Serial.println( mpu6050_print_values() );           //  Imprimir a traves de rutina
        
    delay(1000);
}

