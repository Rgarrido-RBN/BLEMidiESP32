/*
 * gpioESP32.cpp
 *
 *  Created on: Nov 12, 2021
 *      Author: rbn
 */

#include "gpio/gpioESP32.h"
extern "C"
{
	#include "gpio/gpioDefinition.h"
}

gpioESP32::gpioESP32(int pinName, int interruptMode, int pinMode, int pullMode):
	mPinName(pinName),mInterruptMode(interruptMode),mPinMode(pinMode),mPullMode(pullMode)
{
	gpioInitPin(mPinName, mInterruptMode, mPinMode, mPullMode);
}

gpioESP32::~gpioESP32() {
	// TODO Auto-generated destructor stub
}

bool gpioESP32::getValue()
{	
	//TODO: Implement logic
	return true;
}

bool gpioESP32::togglePin()
{
	//TODO: Implement logic
	return true;
}

void gpioESP32::setValue(int valueToSet)
{
	gpio_set_level((gpio_num_t)mPinName, valueToSet);
}

void gpioESP32::enableInterruptPin(int pin)
{
	setButtonInterruptCallback(pin);
}