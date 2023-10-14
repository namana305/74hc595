#ifndef _LEDRUNNING_H
#define _LEDRUNNING_H
#include <Arduino.h>
class LedRunning
{
private:
  int timeStamp;
  bool led_sate = 0;
  uint8_t led_pin = 13;
  bool isRunning = false;
public:
  LedRunning();
  ~LedRunning();
  void initialize(int led_pin_to_set);
  void loop(unsigned long delay_time);
  void start();
  void stop();
};

#endif