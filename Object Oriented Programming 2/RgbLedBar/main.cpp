#include <iostream>
#include <ctime>
#include "RgbLedBar.h"

using namespace std;
using namespace Hardware;
using namespace Visual;

int main()
{
     /*
     RgbLed aliveLed;

     cout << "Red = " << aliveLed.getColor().getRed() << endl;
     cout << "Green = " << aliveLed.getColor().getGreen() << endl;
     cout << "Blue = " << aliveLed.getColor().getBlue() << endl;

     cout << "Setting the color of the led to yellow:" << endl;
     aliveLed.setColor(Visual::Color(88, 88, 0));

     cout << "Red = " << aliveLed.getColor().getRed() << endl;
     cout << "Green = " << aliveLed.getColor().getGreen() << endl;
     cout << "Blue = " << aliveLed.getColor().getBlue() << endl;
     */

     cout << "Welcome to LED Bar Demo ..." << endl;

     unsigned int numberOfLeds = 0;
     cout << "How many leds would you like to add to the ledbar? ";
     cin >> numberOfLeds;

     cout << endl;
     cout << "Creating a ledbar with ";
     cout << numberOfLeds << " leds" << endl;

     RgbLedBar bar(numberOfLeds);
     cout << bar.getString() << endl;

     cout << endl;
     cout << "Let us set some random colors:" << endl;

     srand(time(NULL)); // NULL = 0 in C++
     for (unsigned int i = 0; i < bar.getLength(); i++)
     {
          bar.getLed(i)->setColor(Color(rand() % 255, rand() % 255, rand() % 255));
     }
     cout << bar.getString() << endl;

     return 0;
}