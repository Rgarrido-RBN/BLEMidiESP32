/*
 * Button.h
 *
 *  Created on: Nov 16, 2021
 *      Author: rbn
 */

#ifndef MAIN_INC_BUTTON_BUTTON_H_
#define MAIN_INC_BUTTON_BUTTON_H_

#include "gpio/gpioESP32.h"
#include <memory>

class Button
{
public:
	Button(std::shared_ptr<gpioAbs> button):mButton(button){}
	virtual ~Button(){};
	bool getValue();
private:
	std::shared_ptr<gpioAbs> mButton{nullptr};
};
#endif /* MAIN_INC_BUTTON_BUTTON_H_ */
