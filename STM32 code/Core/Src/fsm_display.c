
#include "fsm_display.h"

#define INIT 0
#define EN0 1
#define EN1 2
#define EN2 3
#define EN3 4
//state for blink LED fsm
#define LED_ON 1
#define LED_OFF 2
//Time
#define scanning 250
#define blink 500

/* Init ------*/
int statusEn = INIT;
int statusLed = INIT;

/* Function -----*/
//Set restart 7SEG display
void reset7Seg(void) {
  statusEn = INIT;
}
//7SEG LED display
void scanning7Seg(void) {
  updateBufferSeg();
  if(statusEn == INIT){
	  setTimer(scanning, enTimer);
	  statusEn = EN0;
  }
  else{
  enOn(statusEn - 1);
  display7SEG(segBuffer[statusEn - 1]);
  }
  if (isTimerEnd(enTimer)) {
    switch (statusEn) {
      case EN0:
        statusEn = EN1;
        break;
      case EN1:
        statusEn = EN2;
        break;
      case EN2:
        statusEn = EN3;
        break;
      case EN3:
        statusEn = EN0;
        break;
      default:
        break;
    }

    setTimer(scanning, enTimer);
  }
}
//Blinky LED have 'color'
void blinkLed(int color) {
  switch(statusLed) {
  case INIT:
    statusLed = LED_ON;
    setTimer(blink, blinkTimer);
    break;
  case LED_ON:
	ledRoad1(color);
	ledRoad2(color);
	if(isTimerEnd(blinkTimer)) {
	  statusLed = LED_OFF;
	  setTimer(blink, blinkTimer);
	}
	break;
  case LED_OFF:
	ledOff();
	if(isTimerEnd(blinkTimer)) {
	  statusLed = LED_ON;
	  setTimer(blink, blinkTimer);
	}
	break;
  default:
	  break;
  }
}
