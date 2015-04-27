/*
 * RelayShield.cpp - Relay Shield library
 * Guilherme Engler Stadelhofer
 */
 
//******************************************************************************
//* Includes
//******************************************************************************

#include <SPI.h>

#include "Config.h"
#include "RelayShield.h"

//******************************************************************************
//* Constructors
//******************************************************************************

RelayShield::RelayShield() {
	for (int i = 0; i < MAX_RELAY_QUANTITY; i++) {
		this->relays[i] = new Relay();
	}
}

//******************************************************************************
//* Public Methods
//******************************************************************************

void RelayShield::begin(int pin[])
{
	for (int i = 1; i <= MAX_RELAY_QUANTITY; i++) {
		this->getRelay(i)->begin(pin[i - 1]);
	}
}

Relay* RelayShield::getRelay(int index)
{
	return this->relays[index - 1];
}

bool RelayShield::acceptableRelayIndex(int index)
{
	return index > 0 && index <= MAX_RELAY_QUANTITY;
}

bool RelayShield::anyRelayActivated()
{
	for (int i = 1; i <= MAX_RELAY_QUANTITY; i++) {
		if (this->getRelay(i)->activated()) {
			return true;
		}
	}
	
	return false;
}