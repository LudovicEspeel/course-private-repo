#include "Animal.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace DateLib;
using namespace AnimalTree;

Animal::Animal(int birthDay, int birthMonth, int birthYear, const string &food) : food(food)
{
    Date birthdate(birthDay, birthMonth, birthYear);
    this->birthdate = birthdate;

    cout << "Animal constructor" << endl;
}

Animal::Animal(const Date &birthdate, const string &food) : food(food), birthdate(birthdate)
{
    cout << "Animal constructor" << endl;
}

Animal::~Animal()
{
    cout << "Animal destructor" << endl;
}

// some getters and setters ...
string Animal::getString() const
{
    stringstream ss;
    ss << "Food: " << food << ", birthdate: " << birthdate.getString();
    return ss.str();
}

string Animal::getSound() const
{
    return "Sound: ?";
}