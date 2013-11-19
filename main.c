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
    _delay_cycles(10000);
     turnLeftSlight();
    _delay_cycles(10000);
    turnRightLarge();
    _delay_cycles(10000);
    turnLeftLarge();
    _delay_cycles(10000);
     forward();

}

