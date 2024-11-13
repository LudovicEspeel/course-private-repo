#include "Cat.h"
#include <iostream>
#include <sstream>

using namespace std;

Cat::Cat(string name, int age, string food) : Pet(name, age, food), numberOfLegs(4)
{
}

Cat::~Cat()
{
    cout << "Destroying a Cat" << endl;
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
    return "Miauw!!!";
}