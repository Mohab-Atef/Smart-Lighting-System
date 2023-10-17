#include "i2cmaster.h"
void i2c_init() {
    // Set bit rate register
    TWBR = (uint8_t)I2C_BITRATE;
}
uint8_t i2c_start(uint8_t addr) {
    /* Transmit start condition */
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
    /* Wait until start condition is transmitted */
    while (!(TWCR & (1 << TWINT)));
    /* Check status code */
    if ((TWSR & 0xF8) != TW_START)
        return 1;  /* Error */
    /* Load device address into data register */
    TWDR = addr;
    /* Clear the interrupt flag by setting TWINT */
    TWCR = (1 << TWEN) | (1 << TWINT);
    /* Wait until address is transmitted */
    while (!(TWCR & (1 << TWINT)));
    /* Check status code */
    if ((TWSR & 0xF8) != TW_MT_SLA_ACK)
        return 1;  /* Error */
    return 0;  /* Success */
}
void i2c_stop() {
    /* Transmit stop condition */
    TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
    /* Wait until stop condition is executed */
    while (TWCR & (1 << TWSTO));
}
uint8_t i2c_write(uint8_t data) {
    /* Copy data into data register */
    TWDR = data;
    /* Clear the interrupt flag by setting TWINT */
    TWCR = (1 << TWEN) | (1 << TWINT);
    /* Wait until data is transmitted */
    while (!(TWCR & (1 << TWINT));
    /* Check status code */
    if ((TWSR & 0xF8) != TW_MT_DATA_ACK)
        return 1;  /* Error */
    return 0;  /* Success */
}
uint8_t i2c_readAck() {
    /* Enable acknowledge bit */
    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
    /* Wait until data is received */
    while (!(TWCR & (1 << TWINT));
    return TWDR;
}
uint8_t i2c_readNak() {
    /* Disable acknowledge bit */
    TWCR = (1 << TWEN) | (1 << TWINT);
    /* Wait until data is received */
    while (!(TWCR & (1 << TWINT));
    return TWDR;
}
