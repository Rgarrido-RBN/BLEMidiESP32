/*
 * Button.h
 *
 *  Created on: Nov 20, 2021
 *      Author: rbn
 */

#ifndef MAIN_INC_BUTTON_BUTTONMANAGER_H_
#define MAIN_INC_BUTTON_BUTTONMANAGER_H_

#include "bluetooth/MidiAbs.h"
#include "button/Button.h"
#include <list>
#include <memory>

class ButtonManager
{
public:
    ButtonManager(std::list<buttonPtr> buttonList, std::shared_ptr<MidiAbs> midiInstance);
    virtual ~ButtonManager(){};

private:
    static void manageButtonEventsTask(void *args);
    void createManageButtonsTask();
    void insertButtonInMap();
    std::list<buttonPtr> mButtonList{};
    std::shared_ptr<MidiAbs> mMidiInstance{};
};

#endif /* MAIN_INC_BUTTON_BUTTONMANAGER_H_ */
