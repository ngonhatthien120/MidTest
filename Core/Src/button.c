/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Nhat Thien
 */
#include "button.h"

int buttonN_flag[MAX_BUTTONS] = { 0 };

//signal button pressed
int buttonN_PIN[MAX_BUTTONS] = { GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14 };

int COUNTER = 0;

int KeyReg0[MAX_BUTTONS] = { NORMAL_STATE };
int KeyReg1[MAX_BUTTONS] = { NORMAL_STATE };
int KeyReg2[MAX_BUTTONS] = { NORMAL_STATE };
int KeyReg3[MAX_BUTTONS] = { NORMAL_STATE };

int TimerForKeyPress[MAX_BUTTONS] = { 300 };


int isButtonNPressed(int index) {
	if (buttonN_flag[index] == 1) {
		buttonN_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index) {
	buttonN_flag[index] = 1;
}

void getKeyInput() {
	for (int i = 0; i < MAX_BUTTONS; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(GPIOA, buttonN_PIN[i]);
		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE) {
					//TODO
					subKeyProcess(i);
					TimerForKeyPress[i] = 300;
				}
			} else {
				TimerForKeyPress[i]--;
				if (TimerForKeyPress[i] == 0) {
					//TODO
					if (KeyReg2[i] == PRESSED_STATE) {
						//TODO
						subKeyProcess(i);
					}
					TimerForKeyPress[i] = 100;
					//KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}

