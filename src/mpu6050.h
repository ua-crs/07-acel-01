/*
 *  mpu6050.h
 */

enum mpu_idxs
{
    Ax, //  Accel X
    Ay, //  Accel Y
    Az, //  Accel Z
    T,  //  Temperature
    Gx, //  Gyro X
    Gy, //  Gyro Y
    Gz, //  Gyro Z
    MPU_ITEMS
};

/*
 *  mpu6050_init:
 *      Initializes MPU6050
 *      Receives i2c address
 */

void mpu6050_init(int deviceAddress);

/*
 *  mpu6050_values
 *      Reads all 7 values of mpu6050 (see enum mpu_idxs)
 *      Return pointer where values are stored
 */
double *mpu6050_values(void);

/*
 *  mpu6050_print_values
 *      prints to buffer ll values formatted
 *      return pointer to buffer
 */
char *mpu6050_print_values( void );
