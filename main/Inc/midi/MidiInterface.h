/*
 *  MidiInterface.h
 *
 *  Date: 01 Jan 2023
 *  Author: Rubén Garrido
 *  Mail: rgarrido.rbn@gmail.com
 *
 */

#ifndef MAIN_INC_MIDI_MIDIITERFACE_H_
#define MAIN_INC_MIDI_MIDIITERFACE_H_

#include "bluetooth/MidiBLEAbs.h"
#include "uart/UartMidiAbs.h"
#include <iostream>
#include <memory>

class MidiInterface
{
public:
    MidiInterface(UartMidiAbsPtr uartInstance, MidiBLEAbsPtr bleInstance);
    virtual ~MidiInterface() = default;

    int openMidiBLE();
    int closeMidiBLE();
    int openMidiUART();
    int closeMidiUART();
    int sendMidiMessage(uint8_t *message);

private:
    std::shared_ptr<UartMidiAbs> mUartMidi;
    std::shared_ptr<MidiBLEAbs> mBLEMidi;
};

using MidiInterfacePtr = std::shared_ptr<MidiInterface>;

#endif /* MAIN_INC_MIDI_MIDIITERFACE_H_ */
