/*
 * software_timer.h
 *
 *  Created on: Nov 14, 2023
 *      Author: ASUS TUF
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

/* Define -----*/
//Timer index description
#define enTimer 0
#define road1Timer 1
#define road2Timer 2
#define clockTimer1 3
#define clockTimer2 4
#define mode1Timer 5
#define blinkTimer 6


void setTimer(int duration, int index);
int isTimerEnd(int index);

void timerRun(void);
#endif /* INC_SOFTWARE_TIMER_H_ */
