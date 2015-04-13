/** \example detectingMotions.ino
 * This is an example of how to use the Motion Sensor class.
 * First of all you have to build or buy a PIR Sensor and
 * choose one of the pins to input.
 * Here we are using the digital pin 8.
 */

#include <MotionSensor.h>

MotionSensor p1;

void setup()
{
	Serial.begin(9600);

	//Set the sensor at port 8
	p1.begin(8);

	//Starts checking for motions with a interval time defined by 1 minute
	p1.start(1); 
}
void loop(){
	//Update the sensor
	p1.update();

	//Get if was detected motion in the interval time or not.
	bool motionDetected = p1.read();

	if (motionDetected){
		Serial.println("Movements have been detected.");
	}
	else{
		Serial.println("The interval time has passed whithout any movement detected.");
	}

	delay(1000);

}