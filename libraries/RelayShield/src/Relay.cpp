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

void Relay::begin(int pin)
{
	if (this->pin == 0) {
		this->pin = pin;
		
		pinMode(this->pin, OUTPUT);
		digitalWrite(this->pin, HIGH);
	}
}

bool Relay::toggleState()
{
	if (this->pin == 0) {
		return false;
	}
	
	digitalWrite(this->pin, this->state ? HIGH : LOW);

	// Inverte o estado do relé	
	this->state = !this->state;
	
	return this->state;
}

bool Relay::activated()
{
	return this->state;
}