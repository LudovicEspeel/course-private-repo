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

string Animal::getString() const
{
    stringstream ss;
    ss << "Animal food: " << food << ", age: " << age << " years";
    return ss.str();
}