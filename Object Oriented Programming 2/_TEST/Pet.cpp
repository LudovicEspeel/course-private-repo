#include "Pet.h"
#include <iostream>
#include <sstream>

using namespace std;

Pet::Pet(string name, int age, string food) : Animal(food, age), name(name)
{
}

Pet::~Pet()
{
    cout << "Destroying a Pet" << endl;
}

/*string Pet::getSound() const
{
    return "";
}*/

string Pet::getString() const
{
    stringstream ss;
    ss << Animal::getString() << ", name: " << name;
    return ss.str();
}