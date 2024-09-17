#pragma once
#include "Pet.h"
#include <string>

using namespace std;

class Cat : public Pet
{
    public:
        Cat(string name, int age, string food);
        virtual ~Cat();
        // some getters and setters ...
        virtual string getString() const override;
        virtual string getSound() const override; 
    private:
        int numberOfLegs;
};