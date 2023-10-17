#ifndef HEADER_H
#define HEADER_H
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "i2cmaster.h"  /* I2C library for RTC communication */
/* Define RGB LED control pins */
#define RED_PIN PB1
#define GREEN_PIN PB2
#define BLUE_PIN PB3
/* Define PIR sensor pin */
#define PIR_PIN PC0
/* DS1307 RTC I2C address */
#define RTC_ADDR 0b1101000
/* Define time thresholds for different lighting modes */
#define DAY_MODE_START_HOUR 7
#define DAY_MODE_END_HOUR 19
#define NIGHT_MODE_BRIGHTNESS 50  /* Adjust as needed */
#define DAY_MODE_BRIGHTNESS 255   /* Full brightness */
void initPWM();
void adjustLighting(uint8_t hour);
void readTime(uint8_t* hour, uint8_t* minute, uint8_t* second);
#endif
