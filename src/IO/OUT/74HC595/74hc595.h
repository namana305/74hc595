#ifndef _HC595_H
#define _HC595_H
#include <Arduino.h>
#include <SPI.h>

#define CUSTOM_SHIFTOUT 0
#define CUSTOM_SHIFTOUT_WITH_RESET 1
#define SPI_MODE 2
class hc595
{
private:
    uint8_t clockPin;
    uint8_t latchPin;
    uint8_t dataSerialPin;
    uint8_t bitOrder = MSBFIRST;
    uint8_t resetPin;
    uint8_t enablePin;
    uint8_t Register;
    uint8_t transferMode=SPI_MODE;

public:
    hc595(uint8_t ClockPin, uint8_t LatchPin, uint8_t DataSerialPin);
    hc595(uint8_t ClockPin, uint8_t LatchPin, uint8_t DataSerialPin, uint8_t ResetPin, uint8_t EnablePin);
    ~hc595();
    void init();
    void changeBitOrder(uint8_t BitOrder);
    void send(uint8_t data);
    size_t getRegister();
    size_t turnOn(uint8_t pin);
    size_t turnOff(uint8_t pin);
};

#endif