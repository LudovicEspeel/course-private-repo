#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "WildBird.h"
#include <iostream>
#include <string>

using namespace std;
using namespace AnimalTree;

int main()
{
    Cat cat("Garfield", "fish", 16, 10, 2024);
    cout << cat.getSound() << endl;
    cout << cat.getString() << endl;
    cout << endl;

    Dog dog("Pluto", "meat", 13, 5, 2020);
    cout << dog.getSound() << endl;
    cout << dog.getString() << endl;
    cout << endl;

    Bird bird("Tweety", "seeds", 18, 6, 2022);
    cout << bird.getSound() << endl;
    cout << bird.getString() << endl;
    cout << endl;

    WildBird wildBird("seeds and nuts", 10, 5, 2023);
    cout << wildBird.getSound() << endl;
    cout << wildBird.getString() << endl;
    cout << endl;

    return 0;
}
