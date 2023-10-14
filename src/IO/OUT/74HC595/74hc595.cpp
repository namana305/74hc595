#include "./74hc595.h"


hc595::hc595(uint8_t ClockPin, uint8_t LatchPin, uint8_t DataSerialPin)
{
    clockPin = ClockPin;
    latchPin = LatchPin;
    dataSerialPin = DataSerialPin;
    transferMode = CUSTOM_SHIFTOUT;
}
hc595::hc595(uint8_t ClockPin, uint8_t LatchPin, uint8_t DataSerialPin, uint8_t ResetPin, uint8_t EnablePin)
{
    clockPin = ClockPin;
    latchPin = LatchPin;
    dataSerialPin = DataSerialPin;
    resetPin = ResetPin;
    enablePin = EnablePin;
    transferMode = CUSTOM_SHIFTOUT_WITH_RESET;
}
hc595::~hc595()
{
    // clockPin = NULL;
    // latchPin = NULL;
    // dataSerialPin = NULL;
    // resetPin = NULL;
    // enablePin = NULL;
}
void hc595::init()
{
    pinMode(latchPin,OUTPUT);
}
void hc595::changeBitOrder(uint8_t BitOrder)
{
    bitOrder = BitOrder;
}
void hc595::send(uint8_t Data)
{
    digitalWrite(latchPin, 0);
    shiftOut(dataSerialPin, clockPin, bitOrder, Data);
    digitalWrite(latchPin, 1);
    Register = Data;
}
size_t hc595::getRegister()
{
    return Register;
}
size_t hc595::turnOn(uint8_t pin)
{
    if (pin >= 0 && pin < 8)
    {
        Register = Register & (~(1 << pin));
        digitalWrite(latchPin, 0);
        shiftOut(dataSerialPin, clockPin, bitOrder, Register);
        digitalWrite(latchPin, 1);
        return 1;
    }
    else
        return 0;
}
size_t hc595::turnOff(uint8_t pin)
{
    if (pin >= 0 && pin < 8)
    {
        Register = Register | (1 << pin);
        digitalWrite(latchPin, 0);
        shiftOut(dataSerialPin, clockPin, bitOrder, Register);
        digitalWrite(latchPin, 1);
        return 1;
    }
    else
        return 0;
}