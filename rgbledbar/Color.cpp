#include "Color.h"

using namespace Visual;

Color::Color() {}

Color::Color(int red, int green, int blue)
{
  setColor(red, green, blue);
}

void Color::setColor(int red, int green, int blue)
{
  this->red = red;
  this->green = green;
  this->blue = blue;
}

int Color::getRed() const
{
  return red;
}

int Color::getGreen() const
{
  return green;
}

int Color::getBlue() const
{
  return blue;
}

string Color::getString() const
{
  return "[" + to_string(red) + ", " + to_string(green) + ", " + to_string(blue) + "]";
}