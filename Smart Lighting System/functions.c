#include"header.h"
/* Function to initialize PWM for LED control */
void initPWM() {
    /* Set PWM pins as outputs */
    DDRB |= (1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN);
    /* Set non-inverted fast PWM mode */
    TCCR0 |= (1 << WGM00) | (1 << WGM01);
    /* Set prescaler to 64 for PWM frequency */
    TCCR0 |= (1 << CS00) | (1 << CS01);
    /* Enable PWM for RGB channels */
    TCCR0 |= (1 << COM01) | (1 << COM00) | (1 << COM11) | (1 << COM10);
}
/* Function to adjust lighting based on time and occupancy */
void adjustLighting(uint8_t hour) {
    /* Read PIR sensor to check occupancy */
    if (PINC & (1 << PIR_PIN)) {
        if (hour >= DAY_MODE_START_HOUR && hour < DAY_MODE_END_HOUR) {
            /* Daytime and occupancy, set full brightness */
            OCR0 = DAY_MODE_BRIGHTNESS;
        } else {
            /* Nighttime and occupancy, set reduced brightness */
            OCR0 = NIGHT_MODE_BRIGHTNESS;
        }
    } else {
        /* No occupancy, turn off the lights */
        OCR0 = 0;
    }
}
/* Function to read time from DS1307 RTC */
void readTime(uint8_t* hour, uint8_t* minute, uint8_t* second) {
    i2c_start_wait((RTC_ADDR << 1) | I2C_WRITE);
    i2c_write(0x00); /* Set the register pointer to seconds */
    i2c_rep_start((RTC_ADDR << 1) | I2C_READ);
    *second = i2c_readAck();
    *minute = i2c_readAck();
    *hour = i2c_readNak();
    i2c_stop();
}
