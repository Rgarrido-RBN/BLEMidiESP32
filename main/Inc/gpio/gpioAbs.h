/*
 * gpioAbs.h
 *
 *  Created on: Nov 12, 2021
 *      Author: rbn
 */

#ifndef MAIN_GPIO_GPIOABS_H_
#define MAIN_GPIO_GPIOABS_H_

class gpioAbs {
public:
	gpioAbs(){};
	virtual ~gpioAbs() = default;

	virtual bool getValue();
	virtual void setValue(int valueToSet);
	virtual bool togglePin();
};

#endif /* MAIN_GPIO_GPIOABS_H_ */
