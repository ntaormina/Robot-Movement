#include <msp430.h> 
#include "motors.h"
/*
 * AUTHOR:NIK TAORMINA CADET USAF
 * DATE:19 NOV 13
 * This code is meant to move a robot with two DC motors.
 */
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer


		setUpTimerA();
		turnRightSlight();
		__delay_cycles(1000000);
		turnLeftSlight();
		__delay_cycles(1000000);
		turnRightLarge();
		__delay_cycles(1000000);
		turnLeftLarge();
		__delay_cycles(1000000);
		forward();
		__delay_cycles(1000000);
		reverse();
		__delay_cycles(1000000);

}

