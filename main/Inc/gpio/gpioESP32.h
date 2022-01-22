/*
 * gpioESP32.h
 *
 *  Created on: Nov 12, 2021
 *      Author: rbn
 */

#ifndef MAIN_INC_GPIO_GPIOESP32_H_
#define MAIN_INC_GPIO_GPIOESP32_H_

#include "gpio/gpioAbs.h"

class gpioESP32: public gpioAbs
{
public:
	gpioESP32(int pinName, int interruptMode, int pinMode, int pullMode);
	virtual ~gpioESP32();

	void enableInterruptPin(int pin);
	bool getValue() override;
	void setValue(int valueToSet) override;
	bool togglePin() override;
	int getPin() override;
private:
	int mPinName;
	int mInterruptMode;
	int mPinMode;
	int mPullMode;
};

#endif /* MAIN_INC_GPIO_GPIOESP32_H_ */
