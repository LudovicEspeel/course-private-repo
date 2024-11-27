#include "Cat.h"
#include <sstream>

using namespace AnimalTree;

Cat::Cat(Date birthdate, string food, string name) : birthdate(birthdate), food(food),
                                                     name(name), numberOfLegs(4)
{
    this->birthdate = birthdate; // aggregation
}

Cat::Cat(int birthDay, int birthMonth, int birthYear, string food, string name) : food(food), name(name), numberOfLegs(4)
{
    this->birthdate = Date(birthDay, birthMonth, birthYear); // composition
}

Cat::~Cat()
{
}

string Cat::getSound() const
{
    return "Sound: Miauw!!!";
}

string Cat::getString() const
{
    stringstream ss;
    ss << "Name: " << name << ", birthdate: " << birthdate.getString() << ", number of legs: " << numberOfLegs << ", food: " << food;  
    return ss.str();
}