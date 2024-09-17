#pragma once
#include <string>
#include "Pet.h"

using namespace std;

class Cat : public Pet
{
    public:
        Cat(string name, int age, string food);
        virtual ~Cat();
        // some getters and setters ...
        string getString() const override;
        string getSound() const override;
    private:
        int numberOfLegs;
};