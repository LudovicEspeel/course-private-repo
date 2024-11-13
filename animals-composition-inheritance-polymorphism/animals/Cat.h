#pragma once
#include "Pet.h"
#include <string>

using namespace std;
using namespace DateLib;

namespace AnimalTree
{
    class Cat : public Pet
    {
    public:
        Cat(int birthDay, int birthMonth, int birthYear, const string &food, const string &name);
        virtual ~Cat();
        // some getters and setters ...
        string getString() const override;
        string getSound() const override;

    private:
        int numberOfLegs;
    };
}