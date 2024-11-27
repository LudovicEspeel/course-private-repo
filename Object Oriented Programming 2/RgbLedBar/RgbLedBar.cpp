#include "RgbLedBar.h"
#include <iostream>

using namespace Hardware;

RgbLedBar::RgbLedBar() : RgbLedBar(DEFAULT_SIZE) {}

RgbLedBar::RgbLedBar(unsigned int numberOfLeds)
{
  cout << "constructor" << endl;

  this->numberOfLeds = numberOfLeds;
  leds = new RgbLed[this->numberOfLeds];
}

RgbLedBar::~RgbLedBar()
{
  cout << "destructor" << std::endl;
  delete[] leds;
  leds = nullptr;
}

RgbLed *RgbLedBar::getLed(unsigned int index) const
{
  if (index >= numberOfLeds)
  {
    return nullptr;
  }

  return &leds[index];
}

unsigned int RgbLedBar::getLength() const
{
  return numberOfLeds;
}

string RgbLedBar::getString() const
{
  string output = "RGB Led Bar: ";

  for (unsigned int i = 0; i < numberOfLeds; i++)
  {
    output += leds[i].getString();

    if (i < numberOfLeds - 1)
    {
      output += " <=> ";
    }
  }

  return output;
}