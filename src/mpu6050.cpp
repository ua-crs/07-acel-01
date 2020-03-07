/*
 *  mpu6050.cpp
 */

#include <Arduino.h>
#include <Wire.h>

#include "i2c_ruts.h"
#include "mpu6050.h"

/*
 *  Constants definitions
 */

#include "mpudefs.h"    //  MPU6050 related definitions

#define REG_END    0xffff   //  Mark of end of array in 'ini_regs'

typedef struct
{
    uint16_t mpu_reg;
    uint16_t val_reg;
} ini_reg_t;

static const ini_reg_t ini_regs[] =
{
    { MPU6050_SMPLRT_DIV, 0x07},
    { MPU6050_PWR_MGMT_1, 0x01},
    { MPU6050_PWR_MGMT_2, 0x00},
    { MPU6050_CONFIG, 0x00},
    { MPU6050_GYRO_CONFIG, 0x00},  // set +/-250 degree/second full scale,
    { MPU6050_ACCEL_CONFIG, 0x00}, // set +/- 2g full scale
    { MPU6050_FIFO_EN, 0x00},
    { MPU6050_INT_ENABLE, 0x01},
    { MPU6050_SIGNAL_PATH_RESET, 0x00},
    { MPU6050_USER_CTRL, 0x00},
    { REG_END }
};
    
typedef struct
{
    const char *name;
    int scale;
    double offset;
} acc_info_t;

static const acc_info_t acc_info[MPU_ITEMS] =
{
    {   "Ax", AccelFactor, 0.0 },
    {   "Ay", AccelFactor, 0.0 },
    {   "Az", AccelFactor, 0.0 },
    {   "T ",  340, 36.53 },
    {   "Gx", GyroFactor, 0.0 },
    {   "Gy", GyroFactor, 0.0 },
    {   "Gz", GyroFactor, 0.0 }
};


/*
 *  private variables
 */

static double values[MPU_ITEMS];
static int i2c_address;
static char prbuff[200];

/*
 *  private functions
 */

static void
get_rawdata(void)
{
    unsigned i;

    for (i = 0; i < MPU_ITEMS; ++i)
        values[i] = (double)i2c_get2asint();
}

static void
scale_data(void)
{
    unsigned i;

    for( i = 0; i < MPU_ITEMS; ++i )
        values[i] = values[i] / acc_info[i].scale + acc_info[i].offset;
}

/*
 *  public functions
 */

/*
 *  mpu6050_init:
 *      Initializes MPU6050
 *      Receives i2c address
 */

void
mpu6050_init(int deviceAddress)
{
    const ini_reg_t *p;

    i2c_address = deviceAddress;
    for( p = ini_regs; p->mpu_reg != REG_END; ++p )
        i2c_write(i2c_address, p->mpu_reg, p->val_reg );
}

/*
 *  mpu6050_values
 *      Reads all 7 values of mpu6050 (see enum mpu_idxs)
 *      Return pointer where values are stored
 */
double *
mpu6050_values(void)
{
    i2c_reqdata(i2c_address, MPU6050_ACCEL_XOUT_H, MPU_ITEMS * sizeof(short));
    get_rawdata();
    scale_data();
    return values;
}

/*
 *  mpu6050_print_values
 *      prints to buffer ll values formatted
 *      return pointer to buffer
 */
char *
mpu6050_print_values( void )
{
    unsigned i;
    char temp[50];

    *prbuff = '\0';
    for( i = 0; i < MPU_ITEMS; ++i )
    {
        *temp = '\0';
        snprintf( temp, sizeof(temp), "%s: %7.3f\t", acc_info[i].name, values[i] );
        strcat(prbuff,temp);
    }
    return prbuff;
}

