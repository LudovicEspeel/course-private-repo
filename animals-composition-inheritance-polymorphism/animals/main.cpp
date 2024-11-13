#include "Animal.h"
#include "Pet.h"
#include "Cat.h"
#include "Bird.h"
#include "Date.h"
#include <iostream>

using namespace std;
using namespace AnimalTree;
using namespace DateLib;

void print(Animal *animal)
{
    cout << animal->getString() << endl;
}

int main()
{
    try
    {
        // using aggregation:
        cout << ">>> Create animal 1:" << endl;
        Date birthdate1(5, 8, 2024);
        Animal animal1(birthdate1, "grass"); // e.g. a cow
        cout << animal1.getString() << endl;
        cout << animal1.getSound() << endl;
        cout << endl;

        // using composition:
        cout << ">>> Create animal 2:" << endl;
        Animal animal2(5, 8, 2024, "grass"); // e.g. a cow
        cout << animal2.getString() << endl;
        cout << animal2.getSound() << endl;
        cout << endl;

        cout << ">>> Create pet:" << endl;
        Pet pet(2, 5, 2024, "flakes", "Blub"); // e.g. a goldfish
        cout << pet.getString() << endl;
        cout << pet.getSound() << endl;
        cout << endl;

        cout << ">>> Create cat:" << endl;
        Cat cat(1, 3, 2024, "fish", "Musti");
        cout << cat.getString() << endl;
        cout << cat.getSound() << endl;
        cout << endl;

        // using an array or a container such as vector:.
        cout << ">>> Create array of animals:" << endl;

        Animal animalArray1[] = {animal2, pet, cat};
        for (int i = 0; i < 3; i++)
        {
            // problem: getString() and getSound() of Animal is always executed, not of Pet/Cat!
            cout << animalArray1[i].getString() << endl;
            cout << animalArray1[i].getSound() << endl;
            cout << endl;
            // solution: use pointers!!!
        }

        cout << ">>> Create animal 3:" << endl;
        Animal *animal3 = &pet; // create object in stack
        cout << animal3->getString() << endl;
        cout << animal3->getSound() << endl;
        cout << endl;
        //print(animal3);
        //cout << endl;

        cout << ">>> Create animal 4:" << endl;
        Animal *animal4 = new Bird(8, 8, 2024, "nuts", "Coco"); // create object in heap
        cout << animal4->getString() << endl;
        cout << animal4->getSound() << endl;
        cout << endl;
        delete animal4; // make sure that destructors are virtual!

        cout << ">>> Create array of animal pointers:" << endl;
        Animal *animalArray2[] = {&animal2, &pet, &cat};
        for (int i = 0; i < 3; i++)
        {
            cout << animalArray2[i]->getString() << endl;
            cout << animalArray2[i]->getSound() << endl;
            cout << endl;
        }

        // to make polymorphism work:
        // * use pointer variable to an object (not necessary that's created in the heap)
        // * put virtual next to each method that will be overridden
        // * if using destructors --> set as "virtual" if at least one method is virtual (especially if object is created in
        //   heap!!!)
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}