#include "Pet.h"
#include <iostream>
#include <sstream>

using namespace std;

Pet::Pet(string name, int age, string food) : Animal(food, age), name(name)
{
    // Or if no parameter constructor is provided in Animal:
    //setAge(age);
    //setFood(food);

    // Or (but then these attributes need to be declared als protected in Animal):
    //this->age = age;
    //this->food = food;
}

Pet::~Pet()
{
    cout << "Destroying a Pet" << endl;
}

// some getters and setters ...

string Pet::getString() const
{
    stringstream ss;
    ss << Animal::getString() << ", name: " << name;
    return ss.str();
}

string Pet::getSound() const
{
    return "";
}