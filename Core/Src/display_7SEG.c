/*
 * display_7SEG.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Nhat Thien
 */

#include "main.h"
#include "display_7SEG.h"
#include "software_timer.h"
#include "button.h"
#include "fsm_buttons.h"



void display7SEG(int num) {
    char led7seg [10] = {0x40 , 0x79 , 0x24 , 0x30 , 0x19 , 0x92 , 0x02, 0x78 , 0x0 , 0x10 };
	for (int i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, (led7seg[num] >> i) & 1);
	}
}

void show7SEG() {
		//clear7SEG();
		display7SEG(COUNTER);
}
