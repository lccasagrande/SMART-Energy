/*
 * CurrentSensor.cpp - Current Sensor library
 * Copyright (C) 2015-2016 Guilherme Engler Stadelhofer  All rights reserved.
 */

//******************************************************************************
//* Includes
//******************************************************************************

#include <SPI.h>
#include <VoltageSensor.h>
#include <Config.h>

#include "CurrentSensor.h"

//******************************************************************************
//* Constructors
//******************************************************************************

CurrentSensor::CurrentSensor() {
	
	this->sumCurrent = 0UL;
	this->actualCurrent = 0;
	this->readCount = 0;
}

//******************************************************************************
//* Private Methods
//******************************************************************************

int CurrentSensor::determineQuiescentVoltage()
{
	long value = 0;
	int samples = 1000;
	
	for (int i = 0; i < samples; i++) {
		value += analogRead(this->pin);
		delay(1);
	}
	
	value /= samples;
	
	// map(VQ, 0, 1023, 0, 5000) = Valor em mV
	this->zeroVoltage = int(value);
	
	//this->zeroVoltage = map(value, 0, 1023, 0, 5000);
	
	Serial.print("Quiescent Voltage: ");
	Serial.print(this->zeroVoltage);
	Serial.println(" mV");
}

//******************************************************************************
//* Public Methods
//******************************************************************************
void CurrentSensor::begin(int pin)
{
	if (this->pin == 0) {
		this->pin = pin;
		pinMode(pin, INPUT);
		
		this->determineQuiescentVoltage();
	}
}

void CurrentSensor::update()
{
	int raw = analogRead(this->pin) - this->zeroVoltage;
	this->sumCurrent += (unsigned long)(raw * raw);
	this->readCount++;
	
	if (this->readCount >= CURRENT_SENSOR_SAMPLES) {
		this->actualCurrent = int(sqrt((float)this->sumCurrent/(float)this->readCount) * (75.7576 / 1024.0) * 1000);
		this->readCount = 0;
		this->sumCurrent = 0UL;
	}
}

/*
void CurrentSensor::update()
{
	// Modelo de 30A tem sensibilidade de 66mV/A
	int mVperAmp = 66;
	
	int rawValue = analogRead(this->pin);
	this->sumCurrent += rawValue;
	this->readCount++;
	
	if (this->readCount >= CURRENT_SENSOR_SAMPLES) {
		int rawAverage = (float) this->sumCurrent / (float)this->readCount;
		int voltage = ((rawAverage / 1023.0) * 5000) - this->zeroVoltage;
		this->actualCurrent = int((abs(voltage) / (float)mVperAmp) * 1000);
		
		this->readCount = 0;
		this->sumCurrent = 0UL;
	}
}
*/

int CurrentSensor::read()
{
	return this->actualCurrent;
}