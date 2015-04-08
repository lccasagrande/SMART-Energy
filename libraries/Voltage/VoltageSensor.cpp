#include "VoltageSensor.h"



VoltageSensor::VoltageSensor(int porta)
{
	_porta   = porta;
	_voltage = 0;
}

void VoltageSensor::update()
{
	long value = analogRead(_porta);
	_voltage = map(value, 0, 993, 0, 219); 
}

int VoltageSensor::read()
{
	return _voltage;
}

VoltageSensor::~VoltageSensor()
{
}
