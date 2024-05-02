/*
 * MAX7219.h
 *
 *  Created on: May 1, 2024
 *      Author: jakub
 */

#ifndef INC_MAX7219_H_
#define INC_MAX7219_H_

#include "main.h"

extern SPI_HandleTypeDef hspi2;

typedef enum {
    REG_NO_OP           = 0x00,
    REG_DIGIT_0         = 0x01,
    REG_DIGIT_1         = 0x02,
    REG_DIGIT_2         = 0x03,
    REG_DIGIT_3         = 0x04,
    REG_DIGIT_4         = 0x05,
    REG_DIGIT_5         = 0x06,
    REG_DIGIT_6         = 0x07,
    REG_DIGIT_7         = 0x08,
    REG_DECODE_MODE     = 0x09,
    REG_INTENSITY       = 0x0A,
    REG_SCAN_LIMIT      = 0x0B,
    REG_SHUTDOWN        = 0x0C,
    REG_DISPLAY_TEST    = 0x0F,
} MAX7219_REGISTERS;

void max7219_init();
void max7219_setIntensity(uint8_t intensity);
void max7219_SPIWrite(uint8_t addr, uint8_t data);
void max7219_turnOn();
void max7219_turnOff();
void max7219_setLED(uint8_t row, uint8_t led);
void max7219_setRow(uint8_t row, uint8_t value);
void max7219_clearDisplay();



#endif /* INC_MAX7219_H_ */
