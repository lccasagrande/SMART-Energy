#include "Voltage.h"


Voltage::Voltage(int porta)
{
	_porta = porta;
}

int Voltage::getVoltage()
{
	float value = analogRead(_porta);
	Serial.println((value * 5 / 1023));
	value = ((value * 5 / 1023) * 45.249);

	return (int)value;
}


Voltage::~Voltage()
{
}
