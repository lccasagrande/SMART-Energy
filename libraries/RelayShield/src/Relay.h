/**
 * \class Relay
 * \brief This class allows a interface management to operate
 * Relay´s in an Arduino or any kind of micro controller.
 *
 *
 * \author Guilherme Engler Stadelhofer
 * \version 1.0
 * \since 2015-04-11
**/
 
#ifndef RELAY_H
#define RELAY_H

class Relay {
	
	private:
		int pin; /*!< Holds the port used for the Relay */
		bool state;/*!< Holds the state of the Relay */
		
	public:
		Relay();
		/*! \fn Relay()
			\brief Initializes the variables \a.
		*/
		void begin(int pin);
		/*! \fn void begin(int)
			\brief Initializes the object with the port specified \a.
			\param pin - The port connected to the voltage sensor.
		*/
		bool toggleState();
		/*! \fn bool toggleState()
			\brief Change the state of the Relay to On/Off \a.
			\return state - The actual state of the Relay.
		*/
		bool activated();
		/*! \fn bool activated()
			\brief Return if the Relay are activated or not\a.
			\return state - The state of the Relay.
		*/
	
};

#endif