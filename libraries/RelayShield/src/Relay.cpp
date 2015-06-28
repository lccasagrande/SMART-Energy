/*
 * Relay.cpp - Relay library
 * Guilherme Engler Stadelhofer
 */
//******************************************************************************
//* Includes
//******************************************************************************

#include <SPI.h>
#include "Relay.h"

//******************************************************************************
//* Constructors
//******************************************************************************
Relay::Relay()
{
	this->state = false;
	this->pin = 0;
}

//******************************************************************************
//* Public Methods
//******************************************************************************

void Relay::begin(int pin, int initialOutput)
{
	if (this->pin == 0) {
		this->pin = pin;
		this->initialOutput = initialOutput;
		
		pinMode(this->pin, OUTPUT);
		digitalWrite(this->pin, this->initialOutput);
	}
}

bool Relay::toggleState()
{
	if (this->pin == 0) {
		return false;
	}
	
	if (this->initialOutput == HIGH) {
		digitalWrite(this->pin, this->state ? HIGH : LOW);
	} else {
		digitalWrite(this->pin, this->state ? LOW : HIGH);
	}

	// Inverte o estado do relé	
	this->state = !this->state;
	
	return this->state;
}

bool Relay::activated()
{
	return this->state;
}