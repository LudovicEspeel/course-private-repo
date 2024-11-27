#include <iostream>
using namespace std;

struct node
{
    char data;
    struct node *nextNode;
};

int main(void)
{
    struct node *headPtr = nullptr;

    // node1
    struct node *node1 = new node;
    node1->data = 'A';
    node1->nextNode = nullptr;
    headPtr = node1;

    // append node2 to node1
    struct node *node2 = new node;
    node2->data = 'B';
    node2->nextNode = nullptr;
    node1->nextNode = node2;

    // append node3 to node2
    struct node *node3 = new node;
    node3->data = 'C';
    node3->nextNode = nullptr;
    node2->nextNode = node3;

    // print the nodes
    struct node *tempPtr = headPtr;
    while(tempPtr != nullptr)
    {
        cout << tempPtr->data << " --> ";
        tempPtr = tempPtr->nextNode;
    }
    cout << "NULL" << endl;
}