#include "functions.h"

void appendNode(node **headPtr, char data)
{
    struct node *newPtr = new node;
    newPtr->data = data;
    newPtr->nextNode = nullptr;

    if (*headPtr == nullptr)
    {
        *headPtr = newPtr;
    }
    else
    {
        struct node *tempPtr = *headPtr;
        while (tempPtr->nextNode != nullptr)
        {
            tempPtr = tempPtr->nextNode;
        }
        tempPtr->nextNode = newPtr;
    }
}

void printNodes(node *headPtr)
{
    struct node *tempPtr = headPtr;
    while (tempPtr != nullptr)
    {
        cout << tempPtr->data << " --> ";
        tempPtr = tempPtr->nextNode;
    }
    cout << "NULL" << endl;
}

void removeNode(node **headPtr, char data)
{
    // nulde node bevat al meteen de gevonden data
    while (*headPtr != nullptr && (*headPtr)->data == data)
    {
        struct node *tempPtr = *headPtr;
        *headPtr = (*headPtr)->nextNode;
        delete tempPtr;
    }

    // verdere nodes
    struct node *previousPtr = *headPtr;
    struct node *currentPtr = *headPtr;

    while (currentPtr != nullptr)
    {
        if (currentPtr->data == data)
        {
            struct node *tempPtr = currentPtr;
            previousPtr->nextNode = currentPtr->nextNode;
            currentPtr = currentPtr->nextNode;
            delete tempPtr;
        }
        else
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextNode;
        }
    }
}

void insertNode(node **headPtr, char data, int position)
{
    struct node *newPtr = new node;
    newPtr->data = data;
    newPtr->nextNode = nullptr;

    struct node *previousPtr = nullptr;
    struct node *currentPtr = *headPtr;

    int counter = 0;

    while (currentPtr != nullptr && counter < position)
    {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextNode;
        counter++;
    }

    if (previousPtr == nullptr)
    {
        newPtr->nextNode = *headPtr;
        *headPtr = newPtr;
    }
    else
    {
        previousPtr->nextNode = newPtr;
        newPtr->nextNode = currentPtr;
    }
}