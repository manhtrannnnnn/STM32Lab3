/*
 * fsm_automatic.c
 *
 *  Created on: Nov 14, 2023
 *      Author: ASUS TUF
 */

#include "fsm_automatic.h"

#define INIT 0
#define AUTO_RED 1
#define AUTO_YELLOW 2
#define AUTO_GREEN 3
//Clock counter
#define CLOCK_TIME 1000

/* Init -----*/
int statusRoad1 = INIT;
int statusRoad2 = INIT;

/* Function -----*/
void trafficRoad1(void) {
  if(isTimerEnd(clockTimer1)) {
    timeRoad1--;
    setTimer(CLOCK_TIME, clockTimer1);
  }
  switch(statusRoad1) {
  case INIT:
    statusRoad1 = AUTO_RED;
    timeRoad1 = timeRed;
    setTimer(timeRed * TIME_UNIT, road1Timer);
    setTimer(CLOCK_TIME, clockTimer1);
    break;
  case AUTO_RED:
	ledRoad1(RED);
	if(isTimerEnd(road1Timer) == 1) {
	  statusRoad1 = AUTO_GREEN;
	  timeRoad1 = timeGreen;
	  setTimer(timeGreen * TIME_UNIT, road1Timer);
	  setTimer(CLOCK_TIME, clockTimer1);
	}
    break;
  case AUTO_YELLOW:
	ledRoad1(YELLOW);
	if(isTimerEnd(road1Timer) == 1) {
	  statusRoad1 = AUTO_RED;
	  timeRoad1 = timeRed;
	  setTimer(timeRed * TIME_UNIT, road1Timer);
	  setTimer(CLOCK_TIME, clockTimer1);
	}
    break;
  case AUTO_GREEN:
	ledRoad1(GREEN);
	if(isTimerEnd(road1Timer) == 1) {
	  statusRoad1 = AUTO_YELLOW;
	  timeRoad1 = timeYellow;
	  setTimer(timeYellow * TIME_UNIT, road1Timer);
	  setTimer(CLOCK_TIME, clockTimer1);
	}
    break;
  }
}
void trafficRoad2(void) {
  if(isTimerEnd(clockTimer2)) {
    timeRoad2--;
    setTimer(CLOCK_TIME, clockTimer2);
  }
  switch(statusRoad2) {
  case INIT:
    statusRoad2 = AUTO_GREEN;
    timeRoad2 = timeGreen;
    setTimer(timeGreen * TIME_UNIT, road2Timer);
    setTimer(CLOCK_TIME, clockTimer2);
    break;
  case AUTO_RED:
	ledRoad2(RED);
	if(isTimerEnd(road2Timer) == 1) {
	  statusRoad2 = AUTO_GREEN;
	  timeRoad2 = timeGreen;
	  setTimer(timeGreen * TIME_UNIT, road2Timer);
	  setTimer(CLOCK_TIME, clockTimer2);
	}
    break;
  case AUTO_YELLOW:
	ledRoad2(YELLOW);
	if(isTimerEnd(road2Timer) == 1) {
	  statusRoad2 = AUTO_RED;
	  timeRoad2 = timeRed;
	  setTimer(timeRed * TIME_UNIT, road2Timer);
	  setTimer(CLOCK_TIME, clockTimer2);
	}
    break;
  case AUTO_GREEN:
	ledRoad2(GREEN);
	if(isTimerEnd(road2Timer) == 1) {
	  statusRoad2 = AUTO_YELLOW;
	  timeRoad2 = timeYellow;
	  setTimer(timeYellow * TIME_UNIT, road2Timer);
	  setTimer(CLOCK_TIME, clockTimer2);
	}
    break;
  }
}
//Set state to INIT
void setInit(void) {
  statusRoad1 = INIT;
  statusRoad2 = INIT;
}
