/*
 * display.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS TUF
 */


#include "display.h"
/* Init -----*/
/* LED Pin */
uint16_t LED[numLed] = {RED1_Pin, YELLOW1_Pin, GREEN1_Pin,
                        RED2_Pin, YELLOW2_Pin, GREEN2_Pin};

uint16_t EN[numEn] = {EN0_Pin, EN1_Pin, EN2_Pin, EN3_Pin};

uint16_t SEG7[10] = {0x003f, 0x0006, 0x005b, 0x004f, 0x0066,
		             0x006d, 0x007d, 0x0007, 0x007f, 0x006f};

uint16_t offSEG7[10] = {0x0040, 0x0079, 0x0024, 0x0030, 0x0019,
		             0x0012, 0x0002, 0x0078, 0x0000, 0x0010};
//LED 7SEG buffer
int segBuffer[4] = {0};
/* Function -----*/
/* LED */
//Turn on LED have "color"
void ledRoad1(int color) {
	HAL_GPIO_WritePin(GPIOA, LED[color], 0);
	for(int i = 0; i < numColor; i++) {
	  if(i != color) {
	    HAL_GPIO_WritePin(GPIOA, LED[i], 1);
	  }
	}
}
void ledRoad2(int color) {
	HAL_GPIO_WritePin(GPIOA, LED[numColor + color], 0);
	for(int i = 0; i < numColor; i++) {
	  if(i != color) {
	    HAL_GPIO_WritePin(GPIOA, LED[numColor + i], 1);
	  }
  }
}
//Turn off all LED
void ledOff(void) {
  for(int i = 0; i < numLed; i++) {
    HAL_GPIO_WritePin(GPIOA, LED[i], 1);
  }
}
void enOn(int index) {
  for(int i = 0; i < numEn; i++) {
    if(i == index) {
      HAL_GPIO_WritePin(GPIOA, EN[i], 0);
    }
    else {
      HAL_GPIO_WritePin(GPIOA, EN[i], 1);
    }
  }
}

void updateBufferSeg(void) {
  segBuffer[0] = timeRoad1 / 10;
  segBuffer[1] = timeRoad1 % 10;
  segBuffer[2] = timeRoad2 / 10;
  segBuffer[3] = timeRoad2 % 10;
}

void display7SEG(int num) {
	HAL_GPIO_WritePin(GPIOB, offSEG7[num], SET);
    HAL_GPIO_WritePin(GPIOB, SEG7[num], RESET);
  }
