#include "Animal.h"
#include "Pet.h"
#include "Cat.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /*
    Animal animal("grass", 5);
    //cout << animal.getString() << endl;

    Pet pet("Blub", 6, "flakes");
    //cout << pet.getString() << endl;

    Cat cat("Musti", 3, "fish");
    //cout << cat.getString() << endl;

    //Animal *animal2 = &pet;
    //cout << animal2->getString() << endl;

    Animal *animals[] = { &animal, &pet, &cat };
    //vector<Animal> animals2;
    //animals2.push_back(animal);

    for(int i = 0; i < 3; i++)
    {
        cout << animals[i]->getString() << endl;
        cout << animals[i]->getSound() << endl;
    }
    */



    //Animal animal("grass", 5);
    //cout << animal.getString() << endl;

    Pet pet("Blub", 6, "flakes");
    //cout << pet.getString() << endl;

    Cat cat("Musti", 3, "fish");
    //cout << cat.getString() << endl;

    //Animal *animal2 = &pet;
    //cout << animal2->getString() << endl;

    Animal *animals[] = { &pet, &cat };
    //vector<Animal> animals2;
    //animals2.push_back(animal);

    for(int i = 0; i < 3; i++)
    {
        cout << animals[i]->getString() << endl;
        cout << animals[i]->getSound() << endl;
    }

    return 0;
}