#include "functions.h"
#include "node.h"
#include <iostream>
using namespace std;

int main()
{
    struct node *headPtr = nullptr;

    appendNode(&headPtr, 'A');
    appendNode(&headPtr, 'B');
    appendNode(&headPtr, 'C');
    appendNode(&headPtr, 'D');
    appendNode(&headPtr, 'E');
    appendNode(&headPtr, 'F');
    appendNode(&headPtr, 'B');

    printNodes(headPtr);

    removeNode(&headPtr, 'B');

    printNodes(headPtr);

    insertNode(&headPtr, 'B', 2);

    printNodes(headPtr);
    
    return 0;
}