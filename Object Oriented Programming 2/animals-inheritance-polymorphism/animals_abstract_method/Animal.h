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

        // "pure" virtual method (= "abstract" in C#/Java): method without implementation.
        // It must be overridden in the derived classes (not necessary in the direct derived class)!
        virtual string getSound() const = 0; 

        // Important notes: 
        // * If at least one method is declared as "pure", then we consider this class as an "abstract" class. It's no 
        //   longer allowed to create an instance of this class in e.g. the main.
        // * If all methods are abstract + the constructor and destructor are removed, then you can consider this class 
        //   as an "interface". Unfortunately, we don't have the keywords "abstract" and "interface" in C++.
    private:
        string food;
        int age;
};