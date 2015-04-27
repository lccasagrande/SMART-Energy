/*
 * VoltageSensor.cpp - Voltage Sensor library
 * Lucas C. Casagrande
 */

//******************************************************************************
//* Includes
//******************************************************************************

#include "VoltageSensor.h"

//******************************************************************************
//* Constructors
//******************************************************************************

VoltageSensor::VoltageSensor()
{
	this->_sumVoltage = 0;
	this->_avgVoltage = 0;
	this->_cont = 0;
	this->_divisor = 100;
}
//******************************************************************************
//* Public Methods
//******************************************************************************

void VoltageSensor::begin(int port)
{
	this->_port = port;
}

void VoltageSensor::update()
{
	int value = analogRead(_port);	

	calculateAvg(value);
}

void VoltageSensor::reset()
{
	this->_cont		= 0;
	this->_sumVoltage	= 0;
}

int VoltageSensor::read()
{
	return static_cast<int>(_avgVoltage);
}

void VoltageSensor::setDivisor(int divisor)
{
	this->_divisor = divisor;
}


//******************************************************************************
//* Private Methods
//******************************************************************************

void VoltageSensor::calculateAvg(int value)
{
	_sumVoltage  += map(value, 0, 993, 0, 219);
	_cont++;
	
	if (_cont == _divisor) {
		_avgVoltage = _sumVoltage / _divisor;
		reset();
	}
}
