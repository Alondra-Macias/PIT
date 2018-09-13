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
	/*enable the holding interrupt flags*/
	PIT->CHANNEL[PIT_0].TFLG |= PIT_TFLG_TIF_MASK;
	/*read flags*/
	PIT->CHANNEL[PIT_0].TCTRL;
	/*Disables  timer inerrupts*/
	PIT->CHANNEL[PIT_0].TCTRL &= ~(PIT_TCTRL_TIE_MASK);
	/*Disables timer*/
	PIT->CHANNEL[PIT_0].TCTRL &= ~(PIT_TCTRL_TEN_MASK);

}

void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float periodo){
	/*Gets the time value for the timer*/
	uint32 value = systemClock*periodo/2;
	/*Loads a value to the PIT counter*/
	PIT->CHANNEL[PIT_0].LDVAL = value;
	/*Enables timer interrupt*/
	PIT->CHANNEL[PIT_0].TCTRL |= PIT_TCTRL_TIE_MASK;
	/*Enables timer*/
	PIT->CHANNEL[PIT_0].TCTRL |= PIT_TCTRL_TEN_MASK;
}



void PIT_clockGating(void){
/*enables PIT clocks*/
	SIM->SCGC6 = PIT_CLOCK_GATING;
	/*Sets PITs Module Control Register to enable PIT clock and for timer to continue in debug mode*/
	PIT->MCR = 0;

}


uint8 PIT_getIntrStatus(void){
	/*returns on a safe way the value of the global variable for Interruption Flag*/
	return interruptionFlag;
}

void PIT_clear(void){
	/*Clears Interruption Flag caused by timer*/
	interruptionFlag = 0;
}
