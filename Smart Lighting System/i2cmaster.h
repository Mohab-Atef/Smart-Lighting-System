#ifndef I2CMASTER_H
#define I2CMASTER_H
#include <avr/io.h>
#include <util/twi.h>
#define F_CPU 8000000UL  /* Define your CPU frequency */
#define I2C_BITRATE ((F_CPU / (SCL_CLOCK * 2)) - 8)
/* Define I2C bit rates */
#define SCL_CLOCK 100000L  /* I2C clock frequency in Hz */
void i2c_init();
uint8_t i2c_start(uint8_t addr);
void i2c_stop();
uint8_t i2c_write(uint8_t data);
uint8_t i2c_readAck();
uint8_t i2c_readNak();
#endif
