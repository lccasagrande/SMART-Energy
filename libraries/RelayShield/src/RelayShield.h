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
			\brief Initializes the objects with the port specified to each relay \a.
			\param pin - The port connected to the relay.
		*/
		Relay* getRelay(int index);
		/*! \fn Relay getRelay(int)
			\brief Get the relay with the passed parameter \a.
			\param index - The index of the relay.
			\return Relay - The relay localized at defined index.
		*/
		bool acceptableRelayIndex(int index);
		/*! \fn bool acceptableRelayIndex(int)
			\brief Verify if the max quantity of Relays was reached \a.
			\param index - The index of the relay.
			\return Relay - If the max quantity of Relay was reached.
		*/
		bool anyRelayActivated();
		/*! \fn bool anyRelayActivated()
			\brief Verify if the there are Relay activated \a.
			\return Relay - If there are Relay activated.
		*/

};

#endif