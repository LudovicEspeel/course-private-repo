#include "Pet.h"
#include <sstream>
#include <iostream>

using namespace std;
using namespace DateLib;
using namespace AnimalTree;

Pet::Pet(int birthDay, int birthMonth, int birthYear, const string &food, const string &name) : Animal(birthDay, birthMonth, birthYear, food), name(name)
{
    cout << "Pet constructor" << endl;
}

Pet::~Pet()
{
    cout << "Pet destructor" << endl;
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
    return "Sound ?";
}