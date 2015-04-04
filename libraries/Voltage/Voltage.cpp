#include "Voltage.h"


Voltage::Voltage(int porta)
{
	_porta = porta;
}

int Voltage::getVoltage()
{
	float value = analogRead(_porta);

	value = map(value, 0, 993, 0, 219);

	return (int)value;
}


Voltage::~Voltage()
{
}
