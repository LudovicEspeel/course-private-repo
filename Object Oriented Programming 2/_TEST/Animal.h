#pragma once

#include <string>
using namespace std;

class Animal
{
    public:
        Animal(string food, int age);
        virtual ~Animal();
        // some getters and setters ...
        virtual string getString() const;
        virtual string getSound() const = 0;
    private:
        string food;
        int age;
};