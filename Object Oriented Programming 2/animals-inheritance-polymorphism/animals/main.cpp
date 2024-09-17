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
    Animal animal("grass", 5);
    cout << animal.getString() << endl;
    cout << animal.getSound() << endl;

    Pet pet("Blub", 6, "flakes");
    cout << pet.getString() << endl;
    cout << pet.getSound() << endl;

    Cat cat("Musti", 3, "fish");
    cout << cat.getString() << endl;
    cout << cat.getSound() << endl;

    // Using an array or a container such as vector:
    Animal animals[] = { animal, pet, cat };
    for(int i = 0; i < 3; i++)
    {
        cout << animals[i].getString() << endl; // getString() of Animal is always executed, not of Pet/Cat!
        cout << animals[i].getSound() << endl; // Same problem ...
        // Reason: use pointers!!!
    }

    Animal *animal2 = &pet; // In stack
    cout << animal2->getString() << endl;
    cout << animal2->getSound() << endl;
    print(animal2);

    Animal *animal3 = new Pet("Coco", 12, "Nuts"); // In heap
    cout << animal3->getString() << endl;
    cout << animal3->getSound() << endl;
    delete animal3; // Make sure that destructors are virtual!

    Animal *animals2[] = { &animal, &pet, &cat };
    for(int i = 0; i < 3; i++)
    {
        cout << animals2[i]->getString() << endl;
        cout << animals2[i]->getSound() << endl;
    }


    // To make polymorphism work:
    // * use pointer variable to an object (not necessary that's created in the heap)
    // * put virtual next to each method that will be overridden
    // * if using destructors --> set as "virtual" if at least one method is virtual (especially if object is created in
    //   heap!!!)

    return 0;
}