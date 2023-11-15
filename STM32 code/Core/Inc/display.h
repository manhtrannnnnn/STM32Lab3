/*
 * display.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS TUF
 */

#include "main.h"
#include "global.h"

extern int segBuffer[4];

void ledRoad1(int color);
void ledRoad2(int color);

void ledOff(void);

void enOn(int index);

void updateBufferSeg(void);
void display7SEG(int num);
