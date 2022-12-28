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

typedef enum
{
    PRESET_MODE = 0,
    PEDAL_MODE,
    BANK_MODE
} ButtonModes;

class Button
{
public:
    Button(std::shared_ptr<gpioAbs> button, int buttonMode)
        : mButton(button)
        , mButtonMode(buttonMode)
    {
    }

    Button(std::shared_ptr<gpioAbs> button, std::shared_ptr<Led> led, int buttonMode)
        : mButton(button)
        , mLed(led)
        , mButtonMode(buttonMode)
    {
    }

    virtual ~Button(){};

    bool getValue();

    int getPin();
    int getButtonMode();
    uint8_t *getMidiMessage();

    void setMidiMessage(int status, int note, int velocity);
    void buttonPressed();

private:
    std::shared_ptr<gpioAbs> mButton;
    std::shared_ptr<Led> mLed;
    int mButtonMode;
    uint8_t *mMidiMessage;
};

using buttonPtr = std::shared_ptr<Button>;

#endif /* MAIN_INC_BUTTON_BUTTON_H_ */
