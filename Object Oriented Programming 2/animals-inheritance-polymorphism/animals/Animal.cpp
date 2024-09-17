#include "Animal.h"
#include <iostream>
#include <sstream>

using namespace std;

Animal::Animal(string food, int age) : food(food), age(age)
{
}

Animal::~Animal()
{
    cout << "Destroying an Animal" << endl;
}

// some getters and setters ...

string Animal::getString() const
{
    stringstream ss;
    ss << "food: " << food << ", age: " << age;
    return ss.str();
}

string Animal::getSound() const
{
    return "";
}