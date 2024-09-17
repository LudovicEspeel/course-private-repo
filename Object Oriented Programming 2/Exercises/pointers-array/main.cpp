// make no changes to this file!
#include "functions.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    const int MAX_NUMBER = 10;
    int array[MAX_NUMBER] = {4, 8, 2, 3, 3, 17, 7, 99, 3, 12};

    printf("Original array: ");
    cout << getString(array, MAX_NUMBER) << endl;
    assert(getString(array, MAX_NUMBER) == "4 8 2 3 3 17 7 99 3 12");

    remove(3, array, MAX_NUMBER);  // delete all occurrences of 3
    remove(10, array, MAX_NUMBER); // nothing happens

    printf("Manipulated array: ");
    cout << getString(array, MAX_NUMBER) << endl;
    assert(getString(array, MAX_NUMBER) == "4 8 2 17 7 99 12 0 0 0");

    return 0;
}