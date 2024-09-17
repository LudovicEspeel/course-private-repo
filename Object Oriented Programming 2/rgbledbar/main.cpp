#include <iostream>
#include "RgbLedBar.h"
#include <ctime>

using namespace std;

int main() {

  cout << "Welcome to LED Bar Demo ..." << endl;

  unsigned int numberOfLeds = 0;
  cout << "How many leds would you like to add to the ledbar? ";
  cin >> numberOfLeds;

  cout << endl << "Creating a ledbar with "
    << numberOfLeds << " leds" << endl;

  Hardware::RgbLedBar bar(numberOfLeds);
  cout << bar.getString() << endl;

  cout << endl << "Let us set some random colors:" << endl;

  srand(time(0));
  for (unsigned int i = 0; i < bar.getLength(); i++) {
    bar.getLed(i)->setColor(
      Visual::Color(rand()%255, rand()%255, rand()%255)
    );
  }
  cout << bar.getString() << endl;

  return 0;
}