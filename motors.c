/*
 * Implementation of the functions listed in motors.h
 *
 *  Created on: November 19, 2013
 *      Author: C15Nikolas.Taormina
 */
#include <msp430.h>
#include "motors.h"

void turnRightSlight() {
	P1DIR |= BIT7 | BIT5 | BIT6;
	P1REN |= BIT7 | BIT5 | BIT6;
	P1OUT |= BIT7 | BIT5;
	P1OUT &= ~(BIT1 | BIT3 | BIT4);
	__delay_cycles(1000000);
	P1OUT &= ~(BIT1 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7);

}

void turnLeftSlight() {
	P1DIR |= BIT1 | BIT3 | BIT4;
	P1REN |= BIT1 | BIT3 | BIT4;
	P1OUT |= BIT1 | BIT3;
	P1OUT &= ~(BIT5 | BIT6 | BIT7);
	__delay_cycles(1000000);
	P1OUT &= ~(BIT1 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7);

}

void turnRightLarge() {
	P1DIR |= BIT7 | BIT5 | BIT6;
	P1REN |= BIT7 | BIT5 | BIT6;
	P1OUT |= BIT7 | BIT5;
	P1OUT &= ~(BIT1 | BIT3 | BIT4);
	__delay_cycles(2000000);
	P1OUT &= ~(BIT1 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7);

}

void turnLeftLarge() {
	P1DIR |= BIT1 | BIT3 | BIT4;
	P1REN |= BIT1 | BIT3 | BIT4;
	P1OUT |= BIT1 | BIT3;
	P1OUT &= ~(BIT5 | BIT6 | BIT7);
	__delay_cycles(2000000);
	P1OUT &= ~(BIT1 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7);

}

void forward() {
	P1DIR |= BIT1 | BIT3 | BIT4 | BIT7 | BIT5 | BIT6;
	P1REN |= BIT1 | BIT3 | BIT4 | BIT7 | BIT5 | BIT6;
	P1OUT |= BIT1 | BIT3 | BIT7 | BIT5;
	P1OUT &= ~(BIT4 | BIT6);

}
void reverse() {
	P1DIR |= BIT1 | BIT3 | BIT4 | BIT7 | BIT5 | BIT6;
	P1REN |= BIT1 | BIT3 | BIT4 | BIT7 | BIT5 | BIT6;
	P1OUT &= ~(BIT1 | BIT3 | BIT7 | BIT5);
	P1OUT |= BIT4 | BIT6;

}

void setUpTimerA() {

	P1DIR |= BIT2;                // TA0CCR1 on P1.2
	P1SEL |= BIT2;                // TA0CCR1 on P1.2

//	P2DIR |= BIT2;                // TA0CCR1 on P2.2
//	P2SEL |= BIT2;                // TA0CCR1 on P2.2

	TACTL &= ~MC1 | MC0;            // stop timer A0

	TACTL |= TACLR;                // clear timer A0

	TACTL |= TASSEL1;           // configure for SMCLK

	TACCR0 = 100;   // set signal period to 100 clock cycles (~100 microseconds)

	TACCR1 = 60;
	TACCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

	TACTL |= MC0;                // count up
}

