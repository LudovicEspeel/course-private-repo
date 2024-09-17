#include "Color.h"

namespace Visual {

  Color::Color(void) {
  }

  Color::Color(int red, int green, int blue) {
    setColor(red, green, blue);
  }

  void Color::setColor(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
  }

  int Color::getRed(void) {
    return red;
  }

  int Color::getGreen(void) {
    return green;
  }

  int Color::getBlue(void) {
    return blue;
  }

};