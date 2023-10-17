#include"header.h"
int main() {
    uint8_t hour, minute, second;
    /* Initialize I2C communication for RTC */
    i2c_init();
    /* Initialize PWM for LED control */
    initPWM();
    /* Initialize PIR sensor pin as input */
    DDRC &= ~(1 << PIR_PIN);
    /* Enable global interrupt */
    sei();
    while (1) {
        /* Read the time from the RTC */
        readTime(&hour, &minute, &second);
        /* Adjust lighting based on time and occupancy */
        adjustLighting(hour);
        /* Delay for a suitable period (e.g., 1 minute) */
        _delay_ms(60000);
    }
    return 0;
}
