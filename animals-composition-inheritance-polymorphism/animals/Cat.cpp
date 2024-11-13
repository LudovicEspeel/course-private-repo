#include "Cat.h"
#include <sstream>
#include <iostream>

using namespace std;
using namespace DateLib;
using namespace AnimalTree;

Cat::Cat(int birthDay, int birthMonth, int birthYear, const string &food, const string &name) : Pet(birthDay, birthMonth, birthYear, food, name), numberOfLegs(4)
{
    cout << "Cat constructor" << endl;
}

Cat::~Cat()
{
    cout << "Cat destructor" << endl;
}

// some getters and setters ...

string Cat::getString() const
{
    stringstream ss;
    ss << Pet::getString() << ", numer of legs: " << numberOfLegs;
    return ss.str();
}

string Cat::getSound() const
{
    return "Sound: Miauw!!!";
}