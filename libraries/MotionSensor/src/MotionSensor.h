/**
 * \class MotionSensor
 * \brief This class allows a interface management to operate
 * the PIR sensor in an Arduino or any kind of micro controller.\a
 *
 * \author Lucas C. Casagrande
 * \version 1.0
 * \since 2015-04-12
**/

#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

/*! Milliseconds per minute.*/
#define MILLIS_PER_MIN (60000UL)
/*! Milliseconds per seconds.*/
#define MILLIS_PER_SECS (1000UL)
/*! Seconds per minute.*/
#define SECS_PER_MIN   (60UL)
/*! Converts minutes to milliseconds.*/
#define secsToMillis(_sec_)	  (  _sec_  * MILLIS_PER_SECS)
/*! Converts milliseconds to minutes.*/
#define millisToMinutes(_millis_) ((_millis_ / MILLIS_PER_MIN) % SECS_PER_MIN)
/*! Converts milliseconds to seconds.*/
#define millisToSeconds(_millis_) (_millis_ / MILLIS_PER_SECS)

#include "Arduino.h"

class MotionSensor
{
public:
	MotionSensor();
	/*! \fn MotionSensor()
		\brief Initializes the variables\a.
	*/
	void begin(int);
	/*! \fn void begin(int)
		\brief Initializes the object with the port specified \a.
		\param port - The port connected to the motion sensor.
	*/
	void start(int,int);
	/*! \fn void start(int)
		\brief Starts checking for motions\a.
		\param interval - The interval time to check if was not detected any movement.
		\param relay - The relay number used to control.
	*/
	void stop();
	/*! \fn void stop()
		\brief Stop scanning for motions resetting the time interval to default(0) and setting the motion
		* detected variable to default(1)\a.
	*/
	bool read();
	/*! \fn bool read()
		\brief Get if was detected motion in the interval time or not. \a.
		\return Return if was detected motion or if the time interval has passed with no motion detected.
	*/
	void update();
	/*! \fn void update()
		\brief If the time interval were defined different from the default value 0, this function will update
		* the value of the sensor and will check if the defined interval time passed without detections of motions. 
	*/
	int getInterval();
	/*! \fn int getInterval()
	\brief Get the interval time defined by user or not, converting it from milliseconds to minutes.
	\return The defined interval converted to minutes.
	*/
	int getRelay();
	/*! \fn int getRelay()
	\brief Get the relay defined by user.
	\return The Relay number.
	*/
private:
	int _port;						/*!< Holds the port used for the motion sensor */
	int _relay;						/*!< Holds the relay used to control */
	unsigned long _interval;		/*!< Holds the interval time used to verify the spent time without motion detected */
	unsigned long _previousMillis;	/*!< Holds the time when the verifying started */
	bool _detectedMotion;			/*!< If motion has detected something or no interval time was defined this holds true. If the interval time passed whitout any motion this holds false. */
};

#endif

