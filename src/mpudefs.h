/*
 *  mpudefs.h
 *      MPU6050 related definitions
 *      (taken from data sheet)
 */

// Factores de escala con respecto a fondo de  escala provistos en la hoja de datos
const uint16_t AccelFactor = 16384;
const uint16_t GyroFactor = 131;

// Direcciones de registros de configuracion del MPU6050
const uint8_t MPU6050_SMPLRT_DIV = 0x19;
const uint8_t MPU6050_USER_CTRL = 0x6A;
const uint8_t MPU6050_PWR_MGMT_1 = 0x6B;
const uint8_t MPU6050_PWR_MGMT_2 = 0x6C;
const uint8_t MPU6050_CONFIG = 0x1A;
const uint8_t MPU6050_GYRO_CONFIG = 0x1B;
const uint8_t MPU6050_ACCEL_CONFIG = 0x1C;
const uint8_t MPU6050_FIFO_EN = 0x23;
const uint8_t MPU6050_INT_ENABLE = 0x38;
const uint8_t MPU6050_ACCEL_XOUT_H = 0x3B;
const uint8_t MPU6050_SIGNAL_PATH_RESET = 0x68;


