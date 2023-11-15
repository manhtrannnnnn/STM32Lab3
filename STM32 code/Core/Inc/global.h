/*
 * global.h
 *
 *  Created on: Nov 14, 2023
 *      Author: ASUS TUF
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

/* Traffic Time ----- */
extern int timeRoad1;
extern int timeRoad2;
extern int timeRed;
extern int timeYellow;
extern int timeGreen;

/* Timer -----*/
#define numTimer 7 //Number of timer
#define CYCLE 10 //Timer Cycle = 10ms
#define TIME_UNIT 1000 //1s = 1000ms

/* LED -----*/
#define numLed 6 //Number of LED
#define numEn 4 //Number of 7SEG LED
/* Color */
#define numColor 3
#define RED 0
#define YELLOW 1
#define GREEN 2

/* BUTTON -----*/
#define numButton 3

/* Function -----*/
//Check index (0 <= Index < max)

#endif /* INC_GLOBAL_H_ */
