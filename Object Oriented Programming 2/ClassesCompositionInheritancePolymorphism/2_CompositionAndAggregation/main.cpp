#include "Date.h"
#include "Cat.h"
#include <iostream>
#include <string>

using namespace std;
using namespace DateLib;
using namespace AnimalTree;

int main()
{
    Date date(16, 10, 2024);
    cout << date.getString() << endl;

    Cat cat1("Mousti", "fish", date);
    Cat cat2("Garfield", "fish", 16, 10, 2024);

    cout << cat1.getSound() << endl;
    cout << cat2.getSound() << endl;

    cout << cat1.getString() << endl;
    cout << cat2.getString() << endl;

    return 0;
}
