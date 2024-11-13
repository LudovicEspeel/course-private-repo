#include "Bird.h"
#include <sstream>
#include <iostream>

using namespace std;
using namespace DateLib;
using namespace AnimalTree;

Bird::Bird(int birthDay, int birthMonth, int birthYear, const string &food, const string &name) : Pet(birthDay, birthMonth, birthYear, food, name), numberOfLegs(2), numberOfWings(2)
{
    cout << "Bird constructor" << endl;
}

Bird::~Bird()
{
    cout << "Bird destructor" << endl;
}

// some getters and setters ...

string Bird::getString() const
{
    stringstream ss;
    ss << Pet::getString() << ", number of legs: " << numberOfLegs << ", number of wings: " << numberOfWings;
    return ss.str();
}

string Bird::getSound() const
{
    return "Sound: Tjilp!!!";
}