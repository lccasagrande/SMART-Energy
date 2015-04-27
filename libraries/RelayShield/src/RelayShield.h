/**
 * \class RelayShield
 * \brief This class allows a interface management to operate
 * more than one Relay in an Arduino or any kind of micro controller.
 *
 * It should be used with Relay Library.
 *
 *
 * \author Guilherme Engler Stadelhofer
 * \version 1.0
 * \since 2015-04-11
**/

#ifndef RELAY_SHIELD_H
#define RELAY_SHIELD_H

#include <Config.h>
#include "Relay.h"

class RelayShield {
	
	private:
		Relay* relays[MAX_RELAY_QUANTITY]; /*!< Holds a array of Relays */
		
	public:
		RelayShield();
		/*! \fn RelayShield()
			\brief Initializes the variables \a.
		*/
		void begin(int pin[]);
		/*! \fn void begin(int)
			\brief Initializes the objects with the port specified\a.
			\param pin - The port connected to the relay.
		*/
		Relay* getRelay(int index);
		/*! \fn Relay getRelay(int)
			\param index - The index of the relay.
			\return Relay - The relay localized at defined index.
		*/
		bool acceptableRelayIndex(int index);
		bool anyRelayActivated();
};

#endif