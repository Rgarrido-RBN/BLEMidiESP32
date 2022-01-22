/*
 * BLEMidiESP32.h
 *
 *  Created on: Dec 26, 2021
 *      Author: rbn
 */

#ifndef MAIN_INC_BLUETOOTH_BLEMIDIESP32_H_
#define MAIN_INC_BLUETOOTH_BLEMIDIESP32_H_

#include <memory>
#include "bluetooth/MidiAbs.h"

class BLEMidiESP32: public MidiAbs
{
    public:
        BLEMidiESP32();
        virtual ~BLEMidiESP32();

        int init() override;
        int stop() override;
        int sendMessage(uint8_t* message) override;
        int outputFlush() override;
        int midiTick() override;

    private:
        static void bleMidiCallback(uint8_t blemidi_port, uint16_t timestamp, uint8_t midi_status, uint8_t *remaining_message, size_t len, size_t continued_sysex_pos);
};

using BLEMidiESP32Ptr = std::shared_ptr<BLEMidiESP32>;

#endif