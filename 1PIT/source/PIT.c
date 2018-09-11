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

void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float perior){
	//periodo
	//mascara para el clock
}



void PIT_clockGating(void){
	//prender el registro donde existe el PIT
	//23 sim 6
}

uint8 PIT_interruptFlagStatus(void){
//TIE	el estatus de la bandera TIE
}
//cada vez que este en 0 o
//toggle del puerto D pin 0
//mientras PIN0=FALSE se hace la interrupcion

uint8 PIT_getIntrStatus(void){
	//leer el status de la bandera y regreso este dato Tflag
}

void PIT_clear(void){
	//limpiar banderas que habilite
}
