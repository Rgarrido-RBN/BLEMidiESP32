/*
 * MidiAbs.h
 *
 *  Created on: Dec 26, 2021
 *      Author: rbn
 */
#ifndef MAIN_INC_BLUETOOTH_MIDIABS_H_
#define MAIN_INC_BLUETOOTH_MIDIABS_H_

class MidiAbs
{
public:
    MidiAbs(){};
    virtual ~MidiAbs() = default;

    virtual int init();
    virtual int stop();
    virtual int sendMessage(uint8_t* message);
    virtual int outputFlush();
    virtual int midiTick();
};

using MidiAbsPtr = std::shared_ptr<MidiAbs>;

#endif