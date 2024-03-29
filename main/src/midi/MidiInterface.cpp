/*
 *  MidiInterface.cpp
 *
 *  Date: 02 Jan 2023
 *  Author: Rubén Garrido
 *  Mail: rgarrido.rbn@gmail.com
 *
 */

#include "midi/MidiInterface.h"
extern "C"
{
#include "esp_log.h"
}
static const char *TAG = "MidiInterface";

MidiInterface::MidiInterface(UartMidiAbsPtr uartInstance, MidiBLEAbsPtr bleInstance)
    : mUartMidi(uartInstance)
    , mBLEMidi(bleInstance)
{
    esp_log_level_set(TAG, ESP_LOG_DEBUG);

    // openMidiBLE();
    // openMidiUART();
    // TODO empty constructor
}

int MidiInterface::openMidiBLE()
{
    if(mBLEMidi->getBLEMidiStatus())
    {
        ESP_LOGE(TAG, "BLE MIDI PREVIOUSLY OPEN");
        return -1;
    }
    else
    {
        mBLEMidi->init();
        return 0;
    }
}

int MidiInterface::closeMidiBLE()
{
    if(!mBLEMidi->getBLEMidiStatus())
    {
        ESP_LOGE(TAG, "BLE MIDI PREVIOUSLY CLOSED");
        return -1;
    }
    else
    {
        mBLEMidi->init();
        return 0;
    }
}

int MidiInterface::openMidiUART()
{
    if(mUartMidi->getUartMidiStatus())
    {
        ESP_LOGE(TAG, "UART MIDI PREVIOUSLY OPENED");
        return -1;
    }
    else
    {
        mUartMidi->init();
        return 0;
    }
}

int MidiInterface::closeMidiUART()
{
    if(!mUartMidi->getUartMidiStatus())
    {
        ESP_LOGE(TAG, "UART MIDI PREVIOUSLY CLOSED");
        return -1;
    }
    else
    {
        mUartMidi->init();
        return 0;
    }
}

int MidiInterface::sendMidiMessage(uint8_t *message)
{
     if(mUartMidi->getUartMidiStatus())
     {
        ESP_LOGI(TAG, "Sending Uart message");
        mUartMidi->sendMessage(message);
     }
     if(mBLEMidi->getBLEMidiStatus())
     {
        ESP_LOGD(TAG, "Sending midi message");
        mBLEMidi->sendMessage(message);
     }
    return 0;
}
