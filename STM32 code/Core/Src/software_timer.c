/*
 * software_timer.c
 *
 *  Created on: Nov 14, 2023
 *      Author: ASUS TUF
 */

#include "software_timer.h"


int counter[numTimer] = {0};
int timerFlag[numTimer] = {0};


void setTimer(int duration, int index){
	counter[index] = duration / CYCLE;
	timerFlag[index] = 0;
}


void timerRun(){
	for(int i = 0; i < numTimer; i++){
		if(counter[i] > 0){
			counter[i]--;
			if(counter[i] <= 0){
				timerFlag[i] = 1;
				counter[i] = 0;
			}
		}
	}
}
int isTimerEnd(int index) {
	if(timerFlag[index] == 1) {
		timerFlag[index] = 0;
		return 1;
	}
	return 0;
}
