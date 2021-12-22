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

void Button::convertToPresetButton()
{
    mPresetMode = true;
    mPedalMode = false;
    mBankMode = false;
}
void Button::convertToPedalButton()
{
    mPedalMode = true;
    mPresetMode = false;
    mBankMode = false;

}
void Button::convertToBankButton()
{
    mBankMode = true;
    mPresetMode = false;
    mPedalMode = false;
}
void Button::buttonPressed()
{
     // TODO: Implememt logidc depending button mode
}