#include <Voltage.h>
Voltage voltage(0);


void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.println("------------------------");
	Serial.println(voltage.getVoltage());
	delay(1000);
}
