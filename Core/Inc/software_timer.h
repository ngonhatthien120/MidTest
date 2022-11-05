/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nhat Thien
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIMER_CYCLE  10


extern int timerChange_flag;
extern int timerDown_flag;
extern int timerLed_flag;


void setTimerChange(int duration);
void setTimerDown(int duration);
void setTimerLed(int duration);


void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
