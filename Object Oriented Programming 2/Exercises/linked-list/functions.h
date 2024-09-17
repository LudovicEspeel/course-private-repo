#pragma once
#include "node.h"
#include <iostream>
using namespace std;

void appendNode(node **headPtr, char data);
void printNodes(node *headPtr);
void removeNode(node **headPtr, char data);
void insertNode(node **headPtr, char data, int position);