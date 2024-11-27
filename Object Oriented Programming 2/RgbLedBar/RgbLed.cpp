#include "RgbLed.h"

using namespace Hardware;

RgbLed::RgbLed() : RgbLed(Color(255, 0, 0)) {}

RgbLed::RgbLed(const Color &color)
{
  setColor(color);
}

void RgbLed::setColor(const Color &color)
{
  this->color = color;
}

Color RgbLed::getColor() const
{
  return color;
}

string RgbLed::getString() const
{
  return color.getString();
}