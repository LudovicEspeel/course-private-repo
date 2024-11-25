#include "WildBird.h"
#include <sstream>
#include <iostream>

using namespace std;
using namespace DateLib;
using namespace AnimalTree;

WildBird::WildBird(const string &food, int birthDay, int birthMonth, int birthYear) : Animal(food, birthDay, birthMonth, birthYear),
                                                                                      numberOfLegs(2),
                                                                                      numberOfWings(2)
{
    // cout << "WildBird constructor" << endl;
}

WildBird::~WildBird()
{
    // cout << "WildBird destructor" << endl;
}

string WildBird::getSound() const
{
    return "Sound: Tjilp!!!";
}

string WildBird::getString() const
{
    stringstream ss;
    ss << Animal::getString() << ", ";
    ss << "number of legs: " << numberOfLegs << ", ";
    ss << "number of wings: " << numberOfWings;
    return ss.str();
}