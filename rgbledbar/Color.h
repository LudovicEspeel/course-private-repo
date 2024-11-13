#pragma once

#include <string>

using namespace std;

namespace Visual
{
  class Color
  {
  public:
    Color();
    Color(int red, int green, int blue);
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    void setColor(int red, int green, int blue);
    string getString() const;

  private:
    int red = 0;
    int green = 0;
    int blue = 0;
  };
};