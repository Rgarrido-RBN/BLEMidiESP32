/*
 * MidiBLEAbs.h
 *
 *  Created on: Dec 26, 2021
 *      Author: rbn
 */
#ifndef MAIN_INC_BLUETOOTH_MIDIABS_H_
#define MAIN_INC_BLUETOOTH_MIDIABS_H_

#include <iostream>
#include <memory>

class MidiBLEAbs
{
public:
    MidiBLEAbs(){};
    virtual ~MidiBLEAbs() = default;

    virtual int init();
    virtual int stop();
    virtual int sendMessage(uint8_t *message);
    virtual int outputFlush();
    virtual int midiTick();
    virtual bool getBLEMidiStatus();

protected:
    bool isOpen{false};
};

using MidiBLEAbsPtr = std::shared_ptr<MidiBLEAbs>;

#endif
