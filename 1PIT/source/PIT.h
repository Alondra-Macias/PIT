/*
 * PIT.h
 *
 *  Created on: 16/08/2017
 *      Author: jlpe
 */

#ifndef PIT_H_
#define PIT_H_

#include "MK64F12.h"

#include "DataTypeDefinitions.h"

/*! This enumerated constant are used to select the PIT to be used*/
typedef enum {PIT_0,PIT_1,PIT_2,PIT_3} PIT_Timer_t;

/** Constant that represent the clock enable for GPIO A */
#define PIT_CLOCK_GATING 0x00800000
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This function configure the PIT to generate a delay base on the system clock.
 	 Internally it configures the clock gating and enables the PIT module.
 	 It is important to note that this strictly is not device driver since everything is
 	 contained in a single function, but in general you have to avoid this practices, this only
 	 for the propose of the homework

 	 \param[in]  portName Port to be configured.
 	 \return void
 */

/*ISR for PIT0*/
void PIT0_IRQHandler(void);

/*!
 	 \brief	 
	 This function sets value calculated from clock rate for PIT counter and enables it and its interruption

 	 \param[in]  pitTimer, PIT to be configured.
	 \param[in]  systemClock, clock rate.
	 \param[in]  periodo, period of the signal.
 	 \return void
 */
void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float periodo);

/*!
 	 \brief	 
	 This function enables the clock for PIT peripheral and configures its Module Control Register
 	 \return void
 */
void PIT_clockGating(void);

/*!
 	 \brief	 
	 This function is used to get the interruption status flag

 	 \return uint8 interruptionFlag
 */
uint8 PIT_getIntrStatus(void);

/*!
 	 \brief	 
	 This function is used to set the value of the interruptionFlag to zero

 	 \return void 
 */
void PIT_clear(void);


#endif /* PIT_H_ */
