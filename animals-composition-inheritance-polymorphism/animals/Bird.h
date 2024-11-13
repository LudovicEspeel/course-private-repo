#pragma once
#include "Pet.h"
#include <string>

using namespace std;
using namespace DateLib;

namespace AnimalTree
{
    class Bird : public Pet
    {
    public:
        Bird(int birthDay, int birthMonth, int birthYear, const string &food, const string &name);
        ~Bird();
        // some getters and setters ...
        string getString() const override;
        string getSound() const override;

    private:
        int numberOfLegs;
        int numberOfWings;
    };
}