#pragma once

#include "Color.h"

using namespace std;
using namespace Visual;

namespace Hardware
{
  class RgbLed
  {
  public:
    RgbLed();
    RgbLed(const Color &color);
    Color getColor() const;
    void setColor(const Color &color);
    string getString() const;

  private:
    Color color;
  };
};