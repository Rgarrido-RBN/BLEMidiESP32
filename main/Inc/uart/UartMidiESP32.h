/*
 *  MidiUartESP32.h
 *
 *  Date: 28 Dec 2022
 *  Author: Rubén Garrido
 *  Mail: rgarrido.rbn@gmail.com
 *
 */

#ifndef MAIN_INC_UART_UARTMIDIESP32_H_
#define MAIN_INC_UART_UARTMIDIESP32_H_

#include "uart/UartMidiAbs.h"
#include <memory>

class UartMidiESP32: public UartMidiAbs
{
public:
    UartMidiESP32(int uartPort, int baudrate);
    virtual ~UartMidiESP32() = default;

    int init() override;
    int stop() override;
    int sendMessage(uint8_t *message) override;
    int midiTick() override;
    bool getUartMidiStatus() override;

private:
    static void uartMidiMessageReceived(uint8_t uartmidi_port, uint8_t midi_status, uint8_t *remaining_message,
                                        size_t len, size_t continued_sysex_pos);
    int mUartPort{0};
    int mBaudrate{115200};
};

using UartMidiESP32Ptr = std::shared_ptr<UartMidiESP32>;

#endif /* MAIN_INC_UART_UARTMIDIESP32_H_ */
