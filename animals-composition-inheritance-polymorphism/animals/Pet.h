#pragma once
#include "Animal.h"
#include <string>

using namespace std;
using namespace DateLib;

namespace AnimalTree
{
    class Pet : public Animal
    {
    public:
        Pet(int birthDay, int birthMonth, int birthYear, const string &food, const string &name);
        virtual ~Pet();
        // some getters and setters ...
        virtual string getString() const override;
        virtual string getSound() const override;

    private:
        string name;
    };
}