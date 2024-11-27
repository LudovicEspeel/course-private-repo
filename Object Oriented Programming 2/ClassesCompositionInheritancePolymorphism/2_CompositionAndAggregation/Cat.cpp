#include "Cat.h"
#include <sstream>
#include <iostream>

using namespace AnimalTree;

Cat::Cat(string name, string food, Date birthdate) : name(name),
                                                     food(food),
                                                     // birthdate(birthdate),
                                                     numberOfLegs(4)
{
    this->birthdate = birthdate; // aggregation
    // cout << "Cat constructor" << endl;
}

Cat::Cat(string name, string food, int birthDay, int birthMonth, int birthYear) : name(name),
                                                                                  food(food),
                                                                                  // birthdate(birthDay, birthMonth, birthYear),
                                                                                  numberOfLegs(4)
{
    this->birthdate = Date(birthDay, birthMonth, birthYear); // composition
    // cout << "Cat constructor" << endl;
}

Cat::~Cat()
{
    // cout << "Cat destructor" << endl;
}

string Cat::getSound() const
{
    return "Sound: Miauw!!!";
}

string Cat::getString() const
{
    stringstream ss;
    ss << "Name: " << name << ", ";
    ss << "birthdate: " << birthdate.getString() << ", ";
    ss << "food: " << food << ", ";
    ss << "number of legs: " << numberOfLegs;
    return ss.str();
}