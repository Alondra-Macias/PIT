/*
 * PIT.c
 *
 *  Created on: 11/09/2018
 *      Author: AlondraItzel
 */

#include "PIT.h"

static uint32 interruptionFlag = FALSE;

void PIT0_IRQHandler(void){
	/*Modifies the global variable interruptionFlag value */
	interruptionFlag = PIT->CHANNEL[PIT_0].TFLG;
	PIT->CHANNEL[PIT_0].TFLG |= PIT_TFLG_TIF_MASK;
	PIT->CHANNEL[PIT_0].TCTRL;
	/*Enables interrupts*/
	PIT->CHANNEL[PIT_0].TCTRL |= PIT_TCTRL_TIE_MASK;
	/*Enables timer*/
	PIT->CHANNEL[PIT_0].TCTRL |= PIT_TCTRL_TEN_MASK;

}

void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float perior){
	uint32 value = systemClock*perior;
	PIT->CHANNEL[PIT_0].LDVAL = value;

		/*Enables timer*/
		PIT->CHANNEL[PIT_0].TCTRL |= PIT_TCTRL_TEN_MASK;


	//periodo
	//mascara para el clock
}



void PIT_clockGating(void){
	SIM->SCGC6 = PIT_CLOCK_GATING;
	PIT->MCR = 0;
	PIT->CHANNEL[PIT_0].TCTRL |= PIT_TCTRL_TIE_MASK;
}


uint8 PIT_getIntrStatus(void){
	return interruptionFlag;
}

void PIT_clear(void){
	/*Clears Interruption Flag caused by timer*/
	interruptionFlag = 0;


	//limpiar banderas que habilite
}
