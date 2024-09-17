#pragma once
#include <string>
#include "Animal.h"

using namespace std;

class Pet : public Animal
{
    public:
        Pet(string name, int age, string food);
        virtual ~Pet();
        // some getters and setters ...
        virtual string getString() const override;
        //virtual string getSound() const override;
    private:
        string name;
};