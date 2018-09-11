/*
 * PIT.c
 *
 *  Created on: 11/09/2018
 *      Author: AlondraItzel
 */
#include "PIT.h"


/*PIT_TFLG0 |= PIT_TFLG_TIF_MASK;
PIT_TCTRL0; //read control register for clear PIT flag, this is silicon bug
PIT_TCTRL0 &= ~(PIT_TCTRL_TIE_MASK);//enables PIT timer interrupt
PIT_TCTRL0 &= ~(PIT_TCTRL_TEN_MASK);//enables timer0 */



void PIT0_IRQHandler(void){
	PIT->MCR=0x0;
	//PIT_TFLG0 |= PIT_TFLG_TIF_MASK;
	PIT->CHANNEL[PIT_0].TFLG |=PIT_TFLG_TIF_MASK;
    //PIT->TCTRL0; //read control register for clear PIT flag, this is silicon bug
	PIT->CHANNEL[PIT_0].TCTRL;
	//PIT_TCTRL0 &= ~(PIT_TCTRL_TIE_MASK);//enables PIT timer interrupt
	PIT->CHANNEL[PIT_0].TCTRL  &= ~(PIT_TCTRL_TIE_MASK);//enables PIT timer interrupt
	//PIT_TCTRL0 &= ~(PIT_TCTRL_TEN_MASK);//enables timer0
	PIT->CHANNEL[PIT_0].TCTRL&= ~(PIT_TCTRL_TEN_MASK);//enables timer0
}
void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float periodo){
	PIT->CHANNEL[PIT_0].LDVAL=systemClock*periodo;
	//PIT_LDVAL_TSV=systemClock*periodo;
	//periodo
	//mascara para el clock
	//hacer set al valor que recarga
}



void PIT_clockGating(void){
     SIM->SCGC6=PIT_CLOCK_GATING;
}


//cada vez que este en 0 o
//toggle del puerto D pin 0
//mientras PIN0=FALSE se hace la interrupcion

uint8 PIT_getIntrStatus(void){
return 0;
	//uint8 PIT_TCTRL0;
	//TIE
	//leer el status de la bandera y regreso este dato Tflag
}

void PIT_clear(void){

}
