/*
 * button.h
 *
 *  Created on: Nov 14, 2023
 *      Author: ASUS TUF
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
#include "global.h"


/* Define -----*/
#define mode 0
#define modify 1
#define set 2


void getKeyInput();


int isButtonPressed(int index);


#endif /* INC_BUTTON_H_ */
