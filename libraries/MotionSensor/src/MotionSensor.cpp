/*
* MotionSensor.cpp - MotionSensor Sensor library
* Lucas C. Casagrande
*/

//******************************************************************************
//* Includes
//******************************************************************************

#include "MotionSensor.h"

//******************************************************************************
//* Constructors
//******************************************************************************

MotionSensor::MotionSensor()
{
	this->_interval		  = 0;
	this->_detectedMotion = 0;
	this->_previousMillis = 0;
	this->_relay		  = 0;
}

//******************************************************************************
//* Public Methods
//******************************************************************************

void MotionSensor::begin(int port)
{
	this->_port = port;
}

void MotionSensor::start(int interval, int relay)
{
	//call stop to reset the variables before we start.
	this->_previousMillis = millis();
	this->_interval		  = secsToMillis(interval);
	this->_relay		  = relay;
}

void MotionSensor::stop()
{
	this->_interval		  = 0;
	this->_detectedMotion = 0;
}

bool MotionSensor::read()
{
	return _detectedMotion;
}

void MotionSensor::update()
{	
	if (_interval > 0) 
	{
		bool motionDetected = digitalRead(_port);
		if (motionDetected)
		{
			this->_previousMillis = millis();
			this->_detectedMotion = 0;
		}
		else if ((millis() - _previousMillis) >= _interval)
		{
			this->_detectedMotion = 1;
		}
	}
}

int MotionSensor::getInterval()
{
	int minutes = millisToSeconds(_interval);
	return minutes;
}

int MotionSensor::getRelay()
{
	return this->_relay;
}
