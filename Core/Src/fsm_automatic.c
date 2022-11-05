/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Nhat Thien
 */

#include "fsm_automatic.h"
#include "button.h"
#include "software_timer.h"
#include "fsm_buttons.h"
#include "global.h"

void fsm_automatic_run() {
	switch (status) {
	case NORMAL:
		if (timerChange_flag == 1) {
			status = COUNDOWN;
			setTimerDown(1000);
		}
		break;
	case COUNDOWN:
		if (timerDown_flag == 1 && COUNTER > 0) {
			COUNTER--;
			setTimerDown(1000);
		}
		break;
	default:
		break;
	}
}

