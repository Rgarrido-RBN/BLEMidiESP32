/*
 * Led.cpp
 *
 *  Created on: Nov 16, 2021
 *      Author: rbn
 */

#include "led/Led.h"


Led::~Led() 
{
	// TODO Auto-generated destructor stub
}

void Led::setValue(bool value)
{
	mLed->setValue(value);
}

int Led::toggleLed()
{
	if(!mLed->togglePin())
	{
		return -1;
	}
	return 0;
}