/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Nhat Thien
 */

#include "software_timer.h"

int timerChange_counter = 0;
int timerChange_flag = 0;

int timerDown_counter = 0;
int timerDown_flag = 0;

int timerLed_counter = 0;
int timerLed_flag = 0;

void setTimerChange(int duration) {
	timerChange_counter = duration/TIMER_CYCLE;
	timerChange_flag = 0;
}
void setTimerDown(int duration) {
	timerDown_counter = duration/TIMER_CYCLE;
	timerDown_flag = 0;
}
void setTimerLed(int duration) {
	timerLed_counter = duration/TIMER_CYCLE;
	timerLed_flag = 0;
}

void timerRun() {
	if (timerChange_counter > 0) {
		timerChange_counter--;
		if (timerChange_counter <= 0) {
			timerChange_flag = 1;
		}
	}
	if (timerDown_counter > 0) {
		timerDown_counter--;
		if (timerDown_counter <= 0) {
			timerDown_flag = 1;
		}
	}
	if (timerLed_counter > 0) {
			timerLed_counter--;
			if (timerLed_counter <= 0) {
				timerLed_flag = 1;
			}
		}
}
