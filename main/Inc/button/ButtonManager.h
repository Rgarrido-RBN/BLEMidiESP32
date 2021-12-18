/*
 * Button.h
 *
 *  Created on: Nov 20, 2021
 *      Author: rbn
 */

#ifndef MAIN_INC_BUTTON_BUTTONMANAGER_H_
#define MAIN_INC_BUTTON_BUTTONMANAGER_H_

#include "button/Button.h"
#include <memory>
#include <map>

using buttonPtr = std::shared_ptr<Button>;

class ButtonManager
{
public:

	ButtonManager(buttonPtr button1, buttonPtr button2, 
		buttonPtr button3, buttonPtr button4, buttonPtr button5,
		buttonPtr button6, buttonPtr button7, buttonPtr button8);
	virtual ~ButtonManager(){};

	static void manageButtonEventsTask(void* args);

private:

	void createManageButtonsTask();
	void insertButtonInMap();
	
	buttonPtr mButton1;
	buttonPtr mButton2;
	buttonPtr mButton3;
	buttonPtr mButton4;
	buttonPtr mButton5;
	buttonPtr mButton6;
	buttonPtr mButton7;
	buttonPtr mButton8;

    std::map<int, buttonPtr> mButtonMap;
};

using buttonManagerPtr = std::shared_ptr<ButtonManager>;

#endif /* MAIN_INC_BUTTON_BUTTONMANAGER_H_ */
