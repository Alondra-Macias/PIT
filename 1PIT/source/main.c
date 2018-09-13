/*
 * Copyright (c) 2016, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    PIT_Delay.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "PIT.h"
#include "NVIC.h"
#include "GPIO.h"
#define SYSTEM_CLOCK 21000000
#define DELAY1 0.0005F


int main(){

	uint8 pitIntrStatus = FALSE;
	gpio_pin_control_register_t pinControlRegisterPORTD = GPIO_MUX1;

	//PortD setup
	GPIO_clock_gating(GPIO_D);
	GPIO_pin_control_register(GPIO_D,BIT0,&pinControlRegisterPORTD);
	GPIO_data_direction_pin(GPIO_D,GPIO_OUTPUT,BIT0);
	GPIO_set_pin(GPIO_D,BIT0);   //Enciende el bit0 del puerto D

	//PIT and interruptions setup
	PIT_clockGating();
	NVIC_enableInterruptAndPriotity(PIT_CH0_IRQ, PRIORITY_10);
	EnableInterrupts;

    while(1) {

    	GPIO_toogle_pin(GPIO_D,BIT0);        //Invierte el estado, lo apaga
        PIT_clear();

    	pitIntrStatus = PIT_getIntrStatus();
    	PIT_delay(PIT_0,SYSTEM_CLOCK,DELAY);
    	                               /*Waits for an interruption to occur*/
    	do{
           pitIntrStatus = PIT_getIntrStatus();
    	}while(FALSE == pitIntrStatus);

    }
    return 0 ;
}


