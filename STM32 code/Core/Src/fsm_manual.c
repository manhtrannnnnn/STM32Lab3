/*
 * fsm_manual.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS TUF
 */

#include "fsm_manual.h"

#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4
//Time for fsm
#define RETURN_MODE1 10000

/* Init -----*/
int statusManual = MODE1;

/* Function ----*/
//Auto return to MODE1
void returnMODE1(void) {
  statusManual = MODE1;
  setInit();
}

void fsm_manual(void) {
  switch(statusManual) {
  case MODE1:
    trafficRoad1();
    trafficRoad2();
    if(isButtonPressed(mode) == 1) {
      statusManual = MODE2;
      timeRoad1 = MODE2;
      timeRoad2 = timeRed;
      reset7Seg();
      setTimer(RETURN_MODE1, mode1Timer);
    }
    break;
  case MODE2:
	blinkLed(RED);
	if(isButtonPressed(mode) == 1) {
	  statusManual = MODE3;
	  timeRoad1 = MODE3;
	  timeRoad2 = timeYellow;
      reset7Seg();
	  setTimer(RETURN_MODE1, mode1Timer);
	}
	if(isButtonPressed(modify) == 1) {
		  timeRoad2++;
		  if(timeRoad2 > 99) {
		    timeRoad2 = 0;
		  }
	  setTimer(RETURN_MODE1, mode1Timer);
	}
	if(isButtonPressed(set) == 1) {
	  timeRed = timeRoad2;
	  setTimer(RETURN_MODE1, mode1Timer);
	}
	if(isTimerEnd(mode1Timer) == 1) {
	  reset7Seg();
	  returnMODE1();
	}
	break;
  case MODE3:
	blinkLed(YELLOW);
	if(isButtonPressed(mode) == 1) {
	  statusManual = MODE4;
	  timeRoad1 = MODE4;
	  timeRoad2 = timeGreen;
      reset7Seg();
	  setTimer(RETURN_MODE1, mode1Timer);
	}
	if(isButtonPressed(modify) == 1) {
		  timeRoad2++;
		  if(timeRoad2 > 99) {
		    timeRoad2 = 0;
		  }
	  setTimer(RETURN_MODE1, mode1Timer);
	}
	if(isButtonPressed(set) == 1) {
	  timeYellow = timeRoad2;
	  setTimer(RETURN_MODE1, mode1Timer);
	}
	if(isTimerEnd(mode1Timer) == 1) {
	  reset7Seg();
	  returnMODE1();
	}
	break;
  case MODE4:
	blinkLed(GREEN);
	if(isButtonPressed(mode) == 1) {
	  statusManual = MODE1;
      reset7Seg();
	  setInit();
	}
	if(isButtonPressed(modify) == 1) {
		  timeRoad2++;
		  if(timeRoad2 > 99) {
		    timeRoad2 = 0;
		  }
	  setTimer(RETURN_MODE1, mode1Timer);
	}
	if(isButtonPressed(set) == 1) {
	  timeGreen = timeRoad2;
	  setTimer(RETURN_MODE1, mode1Timer);
	}
	if(isTimerEnd(mode1Timer) == 1) {
	  reset7Seg();
	  returnMODE1();
	}
	break;
  }
}
