/*
 * button.c
 *
 *  Created on: Nov 14, 2023
 *      Author: ASUS TUF
 */

#include "button.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

uint16_t BUTTON[numButton] = {MODE_Pin, MODIFY_Pin, SET_Pin};
int buttonFlag[numButton] = {0};

int keyReg0[numButton] = {NORMAL_STATE};
int keyReg1[numButton] = {NORMAL_STATE};
int keyReg2[numButton] = {NORMAL_STATE};
int keyReg3[numButton] = {NORMAL_STATE};

int TimerForKeyPress[numButton] = {200};

int isButtonPressed(int index){
	if(buttonFlag[index] == 1){
		buttonFlag[index] = 0;
		return 1;
	}
	return 0;
}


void getKeyInput(){
	for(int i = 0; i < numButton; i++){
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
		keyReg2[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON[i]);
		if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i])){
			if(keyReg3[i] != keyReg2[i]){
				keyReg3[i] = keyReg2[i];
				if(keyReg2[i] == PRESSED_STATE){
					//TODO
					buttonFlag[i] = 1;
					TimerForKeyPress[i] = 200;
				}
			}else{
				TimerForKeyPress[i]--;
				if(TimerForKeyPress == 0){
					//TODO
					keyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
