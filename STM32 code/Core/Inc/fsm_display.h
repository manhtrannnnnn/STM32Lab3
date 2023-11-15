/*
 * fsm_display.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS TUF
 */

#ifndef INC_FSM_DISPLAY_H_
#define INC_FSM_DISPLAY_H_

#include "global.h"
#include "software_timer.h"
#include "display.h"

void reset7Seg(void);
void scanning7Seg(void);
void blinkLed(int color);
#endif /* INC_FSM_DISPLAY_H_ */
