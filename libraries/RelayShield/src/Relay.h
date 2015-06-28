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
		int initialOutput;
		
	public:
		Relay();
		/*! \fn Relay()
			\brief Initializes the variables \a.
		*/
		void begin(int pin, int initialOutput);
		/*! \fn void begin(int)
			\brief Initializes the object with the port specified \a.
			\param pin - The port connected to the voltage sensor.
		*/
		bool toggleState();
		bool activated();
};

#endif