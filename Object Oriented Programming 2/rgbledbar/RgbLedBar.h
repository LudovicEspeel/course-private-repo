#pragma once

#include "RgbLed.h"
#include <string>


namespace Hardware {
  class RgbLedBar {

    // Constructors
    public:
      RgbLedBar(void);
      RgbLedBar(unsigned int numberOfLeds);

    // Destructors
    // - Required for freeing dynamically allocated memory
    public:
      ~RgbLedBar(void);

    // Getters
    public:
      RgbLed *getLed(unsigned int index);
      unsigned int getLength(void);

    // Other
    public:
      std::string getString(void);

    // Attributes
    private:
      static const unsigned int DEFAULT_SIZE = 8;
      unsigned int numberOfLeds;
      RgbLed *leds;
  };
};