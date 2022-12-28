/*
 * Button.cpp
 *
 *  Created on: Nov 16, 2021
 *      Author: rbn
 */

#include "button/Button.h"

int Button::getPin()
{
    return mButton->getPin();
}

void Button::buttonPressed()
{
    switch (mButtonMode)
    {
        case PEDAL_MODE:
            mLed->toggleLed();
        break;

        case BANK_MODE:
        break;

        case PRESET_MODE:
            mLed->setValue(true);
        break;
    }
}

void Button::setMidiMessage(int status, int note, int velocity)
{
    mMidiMessage[0] = status;
    mMidiMessage[1] = note;
    mMidiMessage[2] = velocity;
}

uint8_t* Button::getMidiMessage()
{
    return mMidiMessage;
}