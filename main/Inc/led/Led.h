/*
 * Led.h
 *
 *  Created on: Nov 16, 2021
 *      Author: rbn
 */

#ifndef MAIN_INC_LED_LED_H_
#define MAIN_INC_LED_LED_H_

#include "gpio/gpioESP32.h"
#include <memory>

class Led {
public:
	Led(std::shared_ptr<gpioAbs> led):mLed(led){}
	virtual ~Led();
	void setValue(bool value);
private:
	std::shared_ptr<gpioAbs> mLed{nullptr};
};

#endif /* MAIN_INC_LED_LED_H_ */
