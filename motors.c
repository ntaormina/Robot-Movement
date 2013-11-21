/*
 * Implementation of the functions listed in motors.h
 *
 *  Created on: November 19, 2013
 *      Author: C15Nikolas.Taormina
 */
#include <msp430.h>
#include "motors.h"

void turnLeftSlight() {
	TA0CTL &= ~MC0;		//Halts timers
	TA0CTL &= ~MC1;

	TA0CCTL0 |= OUTMOD_5;    //reset
	TA0CCTL1 |= OUTMOD_7;	 //reset/set
	TA0CTL |= MC0;				//count up

	__delay_cycles(500000);				//1 seconds

//	int i = 0;
//		while(i < 1000){
//			if(TACCR0 == TAR){
//				i++;
//			}
//		}

}

void turnRightSlight() {
	TA1CTL &= ~MC0;		//Halts timers
	TA1CTL &= ~MC1;

	TA1CCTL0 |= OUTMOD_5;    //reset
	TA1CCTL1 |= OUTMOD_7;	 //reset/set
	TA1CTL |= MC0;				//count up

	__delay_cycles(500000);				//1 seconds

//	int i = 0;
//			while(i < 1000){
//				if(TACCR0 == TAR){
//					i++;
//				}
//			}

}

void turnLeftLarge() {
	TA0CTL &= ~MC0;		//Halts timers
	TA0CTL &= ~MC1;

	TA0CCTL0 |= OUTMOD_5;    //reset
	TA0CCTL1 |= OUTMOD_7;	 //reset/set
	TA0CTL |= MC0;				//count up

	__delay_cycles(1000000);				//2 seconds

//	int i = 0;
//			while(i < 1000){
//				if(TACCR0 == TAR){
//					i++;
//				}
//			}

}

void turnRightLarge() {
	TA1CTL &= ~MC0;		//Halts timers
	TA1CTL &= ~MC1;

	TA1CCTL0 |= OUTMOD_5;    //reset
	TA1CCTL1 |= OUTMOD_7;	 //reset/set
	TA1CTL |= MC0;				//count up

	__delay_cycles(1000000);				//2 seconds
//	int i = 0;
//			while(i < 1000){
//				if(TACCR0 == TAR){
//					i++;
//				}
//			}

}

void forward() {
	TA0CTL &= ~MC0;		//Halts timers
	TA0CTL &= ~MC1;

	TA0CCTL0 |= OUTMOD_5;
	TA0CCTL1 |= OUTMOD_7;
	TA1CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_7;
	TA0CTL |= MC0;				//count up
	TA1CTL |= MC0;

	__delay_cycles(2000000);			//1 seconds

}
void reverse() {

	TA0CTL &= ~MC0;		//Halts timers
	TA0CTL &= ~MC1;

	TA0CCTL0 &= ~OUTMOD_4;   //right negative motor terminal cleared
	TA0CCTL0 &= ~OUTMOD_5;
	TA0CCTL1 &= ~OUTMOD_7;	 //right positive motor terminal cleared
	TA0CCTL1 &= ~OUTMOD_5;

	TA1CCTL0 &= ~OUTMOD_4;   //left negative motor terminal cleared
	TA1CCTL0 &= ~OUTMOD_5;
	TA1CCTL1 &= ~OUTMOD_7;	 //left positive motor terminal cleared
	TA1CCTL1 &= ~OUTMOD_5;

	TA0CCTL0 |= OUTMOD_4;
	TA0CCTL1 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_4;
	TA1CCTL1 |= OUTMOD_5;
	TA0CTL |= MC0;				//count up
	TA1CTL |= MC0;

	__delay_cycles(1000000);			//1 seconds



}

void fullStop() {
	TA0CTL &= ~(MC1 | MC0);
	TA0CCTL0 &= ~OUTMOD_4;
	TA0CCTL0 &= ~OUTMOD_5;
	TA0CCTL1 &= ~OUTMOD_5;
	TA0CCTL1 &= ~OUTMOD_7;
	TA0CCTL0 |= OUTMOD_5;				//set to reset to stop
	TA0CCTL1 |= OUTMOD_5;
	TA0CTL |= MC0;

	TA1CTL &= ~(MC1 | MC0);
	TA1CCTL0 &= ~OUTMOD_4;
	TA1CCTL0 &= ~OUTMOD_5;
	TA1CCTL1 &= ~OUTMOD_5;
	TA1CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 |= OUTMOD_5;				//set to reset to stop
	TA1CCTL1 |= OUTMOD_5;
	TA1CTL |= MC0;
}

void setUpTimerA() {

	P1DIR |= BIT1;                // TA0.0 on P1.1
	P1SEL |= BIT1;                // TA0.0 on P1.1

	P1DIR |= BIT2;                // TA0.1 on P1.2
	P1SEL |= BIT2;                // TA0.1 on P1.2

	P2DIR |= BIT0;                // TA1.0 on P2.0
	P2SEL |= BIT0;                // TA1.0 on P2.0

	P2DIR |= BIT1;                // TA1.1 on P2.1
	P2SEL |= BIT1;                // TA1.1 on P2.1

	TACTL &= ~MC1 | MC0;            // stop timer A0

	TA0CTL |= TACLR;                // clear timer A0

	TA0CTL |= TASSEL1;           // configure for SMCLK

	TA1CTL |= TACLR;                // clear timer A0

	TA1CTL |= TASSEL1;           // configure for SMCLK

	TACCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TACCR1 = 60;
	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR1 = 60;

	TA0CCTL0 |= OUTMOD_5;
	TA0CCTL1 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_5;

	TA0CTL |= MC0;

	TA1CTL |= MC0;
	// count up
}

