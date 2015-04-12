/** \example VoltageSensor.ino
 * This is an example of how to use the Voltage Sensor class.
 * First of all you have to build or buy a Voltage Sensor and
 * choose one of the analogic pins to input.
 * Here we are using the analogic pin A0.
 **/

#include <VoltageSensor.h>

VoltageSensor v1;

void setup(){
	Serial.begin(9600);
	v1.begin(0);
}

void loop(){
	//Update the sensor value
	v1.update();

	//Get the average of the sensor value.
	int voltage = v1.read();

	//Print the value.
	Serial.print("The Voltage Value is: ");
	Serial.println(voltage);
}
