#ifndef Voltage_h
	#define Voltage_h
	#if defined(ARDUINO) && ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
		#include <pins_arduino.h>
	#endif

	class Voltage
	{
		public:
			Voltage(int porta);
			int getVoltage();
			~Voltage();
		private:
			int _porta;
	};

#endif

