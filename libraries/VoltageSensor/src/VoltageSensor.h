/**
 * \class VoltageSensor
 * \brief This class allows a interface management to operate
 * the voltage sensor in an Arduino or any kind of micro controller.
 *
 *
 * The read function will only return a voltage average value determinated by the divisor variable.
 *
 * Because of that you will have to call the update function in the loop
 * of your sketch to increment the counter who will activate the
 * calculate of the average value.
 *
 * \author Lucas C. Casagrande 
 * \version 1.0
 * \since 2015-04-11
**/

#ifndef VOLTAGE_SENSOR_H	
#define VOLTAGE_SENSOR_H
#include "Arduino.h"

class VoltageSensor
{
	public:
		VoltageSensor();;
		/*! \fn VoltageSensor()
			\brief Initializes the variables \a.
		*/
		int read();
		/*! \fn int read()
			\brief Read the Voltage sensor average \a.
			\return The average of the sensor value.
		*/
		void begin(int);
		/*! \fn void begin(int)
			\brief Initializes the object with the port specified \a.
			\param port - The port connected to the voltage sensor.
		*/
		void update();
		/*! \fn void update()
			\brief Updates the voltage sensor value.
		*/
		void setDivisor(int);
		/*! \fn void setDivisor(int)
			\brief Change the divisor to a user-defined value. \a
			* The divider begins with a default defined as 100 times 
			\param divisor - The divisor used to do the flag activation and to calculate the voltage average.
		*/
		void reset();
		/*! \fn void reset()
			\brief Reset the counter and the voltage sum variables to 0. \a
		*/
	private:
		int _port;  		 /*!< Holds the port used for the voltage sensor */
		int _divisor;		 /*!< The divisor used to calculate the average */
		int _cont;  		 /*!< Counter used as a flag to check when call the average function */
		long _sumVoltage; 	 /*!< Holds the sum of the voltage sensor values */
		long _avgVoltage; 	 /*!< Holds the average of the voltage sensor values */
		void calculateAvg(int); 
		/*! \privatesection
			\fn void calculateAvg(int)
			\brief Increments the updated value received with the sum maded by the  
			* last updates, and increments the counter used as a flag to activate  
			* the calculation function of the voltage average value.\a		
			* 
			* Each time it is updated, the sum of the voltage sensor values 
			* will increase until the time counter activates the calculate 
			* of the voltage average value. When the average is calculated 
			* the variables are reset. \a
			* 
			* The flag activation and the divisor used to calculate the voltage 
			* value average is calculated by the default value of 100 times,
			* but you can change this variable calling the setDiv function.\a.	
			*	
			* The conversion of the sensor value what is analog(0-1023) to a value 
			* what is referent to the Voltage (0-220V), is made by the function of 
			* the arduino called map(). To calibrate this function with your sensor, 
			* you will have to get the maximum read voltage from your socket connected 
			* to the sensor and the maximum read analog value in the pin of arduino. 
			* Then, in the code, you will have to change the parameters of map function 
			* to yours new values. <br> Eg: map(analogRead, 0, maxAnalogRead, 0, maxSocketRead).
			\param value - Holds the last read value of the voltage sensor.
		*/
};





#endif

