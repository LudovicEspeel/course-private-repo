#pragma once

#include "Date.h"
#include <string>

using namespace std;
using namespace DateLib;

namespace AnimalTree
{
    class Animal
    {
    public:
        Animal(const Date &birthDate, const string &food);                       // using aggregation
        Animal(int birthDay, int birthMonth, int birthYear, const string &food); // using composition
        virtual ~Animal();
        // some getters and setters ...
        virtual string getString() const;
        virtual string getSound() const;

    private:
        string food;
        Date birthdate;
    };
}