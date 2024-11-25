#pragma once
// #ifndef CAT_H
// #define CAT_H

#include "Date.h"
#include <string>
using namespace std;
using namespace DateLib;

namespace AnimalTree
{
    class Cat
    {
    public:
        Cat(string name, string food, Date birthdate);
        Cat(string name, string food, int birthDay, int birthMonth, int birthYear);
        ~Cat();
        string getSound() const;
        string getString() const;

    private:
        string name;
        string food;
        Date birthdate;
        int numberOfLegs;
    };
}

// #endif