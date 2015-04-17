 /**
 * \class CurrentSensor
 * \brief This class allows a interface management to operate
 * the current sensor in a Arduino or any kind of micro controller.
 *
 * \author Guilherme Engler Stadelhofer
 * \version 1.0
 * \since 2015-04-02
**/

#ifndef CURRENT_SENSOR_H
#define CURRENT_SENSOR_H

class CurrentSensor {
	
	private:
		int pin; /*!< Holds the port used for the current sensor */		
		int zeroVoltage; /*!< Holds the zero Voltage calculated */
		int actualCurrent; /*!< Holds the actual current average */
		int readCount; /*!< Counter used to do the current average */
		unsigned long sumCurrent; /*!< Holds the sum of the current sensor values */
		int determineQuiescentVoltage();
		/*! \fn int determineQuiescentVoltage()
			\brief Determine the zero Voltage \a.
			\param pin - Return the zero voltage calculated.
		*/
		
	public:
		CurrentSensor();
		/*! \fn CurrentSensor()
			\brief Initializes the variables \a.
		*/
		void begin(int pin);
		/*! \fn void begin(int)
			\brief Initializes the object with the port specified \a.
			\param pin - The port connected to the current sensor.
		*/
		void update();
		/*! \fn void update()
			\brief Updates the current sensor value.
		*/
		int read();
		/*! \fn int read()
			\brief Read the Current sensor average \a.
			\return The average of the sensor value.
		*/
	
};

#endif