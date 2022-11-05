/*
 * fsm_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Nhat Thien
 */
#include "fsm_buttons.h"
#include "button.h"
#include "fsm_automatic.h"
#include"software_timer.h"
#include "global.h"

int isAnyButtonNPressed = 0;
void fsm_simple_buttons_run (){
	//RESET
	if (isButtonNPressed(0) == 1) {
			//Todo
		COUNTER = 0;
		isAnyButtonNPressed = 1;
	}
	//INC
	if (isButtonNPressed(1) == 1) {
			//Todo
		COUNTER++;
		if(COUNTER > 9) COUNTER = 0;
		isAnyButtonNPressed = 1;
	}
	//DEC
	if (isButtonNPressed(2) == 1) {
			//Todo
		COUNTER--;
		if(COUNTER < 0) COUNTER = 9;
		isAnyButtonNPressed = 1;
	}
	if(isAnyButtonNPressed == 1) {
		status = NORMAL;
		setTimerChange(10000);
		isAnyButtonNPressed = 0;
	}
}
