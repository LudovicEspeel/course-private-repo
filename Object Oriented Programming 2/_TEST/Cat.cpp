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

string Cat::getSound() const
{
    return "Miaauw!!!";
}

string Cat::getString() const
{
    stringstream ss;
    ss << Pet::getString() << ", number of legs: " << numberOfLegs;
    return ss.str();
}