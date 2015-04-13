/*
* MotionSensor.cpp - MotionSensor Sensor library
* Copyright (C) 2015-2016 Lucas C. Casagrande  All rights reserved.
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
	this->_detectedMotion = 1;
	this->_previousMillis = 0;
}

//******************************************************************************
//* Public Methods
//******************************************************************************

void MotionSensor::begin(int port)
{
	this->_port = port;
}

void MotionSensor::start(int interval)
{
	//call stop to reset the variables before we start.
	this->_previousMillis = millis();
	this->_interval		  = minutesToMillis(interval);
}

void MotionSensor::stop()
{
	this->_interval		  = 0;
	this->_detectedMotion = 1;
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
			this->_detectedMotion = 1;
		}
		else if ((millis() - _previousMillis) >= _interval)
		{
			this->_detectedMotion = 0;
		}
	}
}

int MotionSensor::getInterval()
{
	int minutes = millisToMinutes(_interval);
	return minutes;
}
