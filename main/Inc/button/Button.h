/*
 * Button.h
 *
 *  Created on: Nov 16, 2021
 *      Author: rbn
 */

#ifndef MAIN_INC_BUTTON_BUTTON_H_
#define MAIN_INC_BUTTON_BUTTON_H_

#include "gpio/gpioESP32.h"
#include "led/Led.h"
#include <memory>

class Button
{
public:
	Button(std::shared_ptr<gpioAbs> button):mButton(button){}
	Button(std::shared_ptr<gpioAbs> button,
	       std::shared_ptr<Led> led):mButton(button), mLed(led){}

	virtual ~Button(){};

	bool getValue();
	int getPin();

	void convertToPresetButton();
	void convertToPedalButton();
	void convertToBankButton();

	void buttonPressed();
private:
	std::shared_ptr<gpioAbs> mButton;
	std::shared_ptr<Led> mLed;

	bool mPresetMode{true}; // Preset mode is default mode
	bool mPedalMode{false};
	bool mBankMode{false};
};
#endif /* MAIN_INC_BUTTON_BUTTON_H_ */
