#include "RgbLedBar.h"
#include <iostream>

namespace Hardware {

  RgbLedBar::RgbLedBar(void)
    : RgbLedBar(DEFAULT_SIZE) {
  }

  RgbLedBar::RgbLedBar(unsigned int numberOfLeds) {
        std::cout << "constructor" << std::endl;

    this->numberOfLeds = numberOfLeds;
    // Dynamically allocate memory for the array of leds
    leds = new RgbLed[this->numberOfLeds];
  }

  RgbLedBar::~RgbLedBar(void) {
    std::cout << "destructor" << std::endl;
    delete[] leds;
    leds = nullptr;
  }

  RgbLed *RgbLedBar::getLed(unsigned int index) {
    if (index >= numberOfLeds) {
      return nullptr;
    }

    return &leds[index];
  }

  unsigned int RgbLedBar::getLength(void) {
    return numberOfLeds;
  }

  std::string RgbLedBar::getString(void) {
    std::string output = "RGB Led Bar: ";
    for (unsigned int i = 0; i < numberOfLeds; i++) {
      output += leds[i].getString();
      if (i < numberOfLeds-1) {
         output += " <=> ";
      }
    }
    return output;
  }

};