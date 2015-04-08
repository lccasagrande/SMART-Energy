#ifndef VOLTAGE_SENSOR_H	
#define VOLTAGE_SENSOR_H
#include "Arduino.h"

class VoltageSensor
{
	public:
		VoltageSensor(int porta);
		void update();
		int read();
		~VoltageSensor();
	private:
		int _porta;
		int _voltage;
};

#endif

