#pragma once

#include "RgbLed.h"
#include <string>

using namespace std;

namespace Hardware
{
  class RgbLedBar
  {
  public:
    RgbLedBar();
    RgbLedBar(unsigned int numberOfLeds);
    ~RgbLedBar();
    RgbLed *getLed(unsigned int index) const;
    unsigned int getLength() const;
    string getString() const;

  private:
    static const unsigned int DEFAULT_SIZE = 8;
    unsigned int numberOfLeds;
    RgbLed *leds;
  };
};