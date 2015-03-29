#include "Voltage.h"


Voltage::Voltage(int porta)
{
	_porta = porta;
}

int Voltage::getVoltage()
{
	float value = analogRead(_porta);

	// (220 / 4.29) = 51.3
	value = ((value * 5 / 1023) * 51.3);

	return (int)value;
}


Voltage::~Voltage()
{
}
