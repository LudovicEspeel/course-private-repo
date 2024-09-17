#include "Animal.h"
#include "Pet.h"
#include "Cat.h"
#include <iostream>

using namespace std;

void print(Animal *animal)
{
    cout << animal->getString() << endl;
}

int main()
{
    // Not possible to create an instance of an abstract class:
    /*  
    Animal animal("grass", 5); 
    Animal *animalb = new Animal("grass", 5);
    cout << animal.getString() << endl;
    cout << animal.getSound() << endl;
    */

    Pet pet("Blub", 6, "flakes");
    cout << pet.getString() << endl;
    cout << pet.getSound() << endl;

    Cat cat("Musti", 3, "fish");
    cout << cat.getString() << endl;
    cout << cat.getSound() << endl;

    Animal *animals[] = { &pet, &cat };
    for(int i = 0; i < 3; i++)
    {
        cout << animals[i]->getString() << endl;
        cout << animals[i]->getSound() << endl;
    }

    return 0;
}