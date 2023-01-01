/*
 *  UartMidiAbs.h
 *  
 *  Date: 28 Dec 2022
 *  Author: Rubén Garrido 
 *  Mail: rgarrido.rbn@gmail.com
 *
 */

#ifndef MAIN_INC_UART_UARTMIDIABS_H_
#define MAIN_INC_UART_UARTMIDIABS_H_

#include <iostream>
#include <memory>

class UartMidiAbs
{
public:
    UartMidiAbs(){};
    virtual ~UartMidiAbs() = default;

    virtual int init();
    virtual int stop();
    virtual int sendMessage(uint8_t* message);
    virtual int outputFlush();
    virtual int midiTick();
};

using UartMidiAbsPtr = std::shared_ptr<UartMidiAbs>;

#endif /* MAIN_INC_UART_UARTMIDIABS_H_ */
