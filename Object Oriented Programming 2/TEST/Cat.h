#pragma once

#include "Date.h"
#include <string>
using namespace std;
using namespace DateLib;

namespace AnimalTree
{
    class Cat
    {
    public:
        Cat(Date birthdate, string food, string name);
        Cat(int birthDay, int birthMonth, int birthYear, string food, string name);
        ~Cat();
        string getString() const;
        string getSound() const;
    private:
        string food;
        string name;
        int numberOfLegs;
        Date birthdate;
    };
}