/*
 * BLEMidiESP32.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: rbn
 */

#include "bluetooth/BLEMidiESP32.h"

extern "C"
{
    #include "blemidi.h"
}

#define DEFAULT_PORT 0

BLEMidiESP32::BLEMidiESP32()
{

}

BLEMidiESP32::~BLEMidiESP32()
{

}

int BLEMidiESP32::init()
{
    return blemidi_init((void*) this->bleMidiCallback);
}

int BLEMidiESP32::stop()
{
    return 0;
}

int BLEMidiESP32::midiTick()
{
    return 0;
}

int BLEMidiESP32::outputFlush()
{
    return blemidi_outbuffer_flush(DEFAULT_PORT);
}

int BLEMidiESP32::sendMessage(uint8_t* message)
{
    return blemidi_send_message(DEFAULT_PORT, message, sizeof(&message));   
}

void BLEMidiESP32::bleMidiCallback(uint8_t blemidi_port, uint16_t timestamp, uint8_t midi_status, uint8_t *remaining_message, size_t len, size_t continued_sysex_pos)
{

}