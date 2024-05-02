#include "MAX7219.h"



void max7219_init() {

	  max7219_SPIWrite(REG_DECODE_MODE, 0x00);
	  max7219_setIntensity(7);
	  max7219_SPIWrite(REG_SCAN_LIMIT, 0x0f); //set all digits
	  max7219_turnOn();
	  max7219_clearDisplay();
}

void max7219_setIntensity(uint8_t intensity) {
	max7219_SPIWrite(REG_INTENSITY, intensity);
}

void max7219_turnOn() {
	max7219_SPIWrite(REG_SHUTDOWN, 0x01);
}
void max7219_turnOff() {
	max7219_SPIWrite(REG_SHUTDOWN, 0x00);
}

void max7219_setLED(uint8_t row, uint8_t led) {
	max7219_SPIWrite(row, (1<<led));
}
void max7219_setRow(uint8_t row, uint8_t value) {
	max7219_SPIWrite(row, value);
}

void max7219_clearDisplay() {
	for(uint8_t i = 1; i < 9; i++) {
		max7219_SPIWrite(i, 0x00);
	}
}

void max7219_SPIWrite(uint8_t addr, uint8_t data) {
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(&hspi2, &addr, 1, HAL_MAX_DELAY);
	HAL_SPI_Transmit(&hspi2, &data, 1, HAL_MAX_DELAY);

	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
}
