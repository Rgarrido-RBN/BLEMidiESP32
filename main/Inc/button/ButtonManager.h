/*
 * Button.h
 *
 *  Created on: Nov 20, 2021
 *      Author: rbn
 */

#ifndef MAIN_INC_BUTTON_BUTTONMANAGER_H_
#define MAIN_INC_BUTTON_BUTTONMANAGER_H_

#include "bluetooth/MidiInterface.h"
#include "button/Button.h"
#include <list>
#include <memory>

class ButtonManager
{
public:
    ButtonManager(std::list<buttonPtr> buttonList, std::shared_ptr<MidiInterface> midiIface);
    virtual ~ButtonManager(){};

private:
    static void manageButtonEventsTask(void *args);
    void createManageButtonsTask();
    void insertButtonInMap();
    std::list<buttonPtr> mButtonList{};
    std::shared_ptr<MidiInterface> mMidiIface{};
};

#endif /* MAIN_INC_BUTTON_BUTTONMANAGER_H_ */
