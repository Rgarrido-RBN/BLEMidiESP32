/*
 *  uartMidiESP23.c
 *
 *  Date: 02 Jan 2023
 *  Author: Rubén Garrido
 *  Mail: rgarrido.rbn@gmail.com
 *
 */

#include "uart/UartMidiESP32.h"

extern "C"
{
#include "esp_log.h"
#include "uartmidi.h"
}

static const char *TAG = "UartMidiESP32";

UartMidiESP32::UartMidiESP32(int uartPort, int baudrate)
    : mUartPort(uartPort)
    , mBaudrate(baudrate)
{
    if(0 == uartmidi_init((void *)uartMidiMessageReceived))
    {
        ESP_LOGI(TAG, "Uart midi created");
    }
    // TODO Create the task
}

int UartMidiESP32::init()
{
    isOpen = true;
    return uartmidi_enable_port(mUartPort, mBaudrate);
}

int UartMidiESP32::stop()
{
    isOpen = false;
    return uartmidi_disable_port(mUartPort);
}

int UartMidiESP32::midiTick()
{
    return uartmidi_tick();
}

int UartMidiESP32::sendMessage(uint8_t *message)
{
    midiTick();
    ESP_LOGD(TAG, "Sending midi note to device");
    return uartmidi_send_message(mUartPort, message, sizeof(&message));
}

bool UartMidiESP32::getUartMidiStatus()
{
    return isOpen;
}

void UartMidiESP32::uartMidiMessageReceived(uint8_t uartmidi_port, uint8_t midi_status, uint8_t *remaining_message,
                                            size_t len, size_t continued_sysex_pos)
{
    // TODO: This needs to be a task who wait for incoming messages
}
