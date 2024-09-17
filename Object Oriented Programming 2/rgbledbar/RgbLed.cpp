#include "RgbLed.h"

using namespace Visual;

namespace Hardware {

  RgbLed::RgbLed(void)
    : RgbLed(Color(255, 0, 0)) {
  }

  RgbLed::RgbLed(Color color) {
    setColor(color);
  }

  void RgbLed::setColor(Color color) {
    this->color = color;
  }

  Color RgbLed::getColor(void) {
    return color;
  }

  std::string RgbLed::getString(void) {
    return color.getString();
  }

};