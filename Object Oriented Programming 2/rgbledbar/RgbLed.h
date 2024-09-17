#pragma once

#include "Color.h"

namespace Hardware {
  class RgbLed {

    // Constructors
    public:
      RgbLed(void);
      RgbLed(Visual::Color color);

    // Setters
    public:
      void setColor(Visual::Color color);

    // Getters
    public:
      Visual::Color getColor(void);
      std::string getString(void);

    // Attributes
    private:
      Visual::Color color;
  };
};