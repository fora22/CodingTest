//
// Created by fora2 on 2020-10-24.
//

#include "foraStackLinkedList.h"

foraStackLinkedList::foraStackLinkedList()
{
    stackHead = new foraStackLinkedListStructure();
}

// foraStackLinkedList::~foraStackLinkedList() {
//     delete[] stackArray;
// }

int& foraStackLinkedList::operator[] (int index)
{
    foraStackLinkedListStructure* findDataPtr = this->stackHead;

    for (int i = 0; i < index; i++) {
        findDataPtr = findDataPtr->tailNode;
    }
    int& tempStackData = findDataPtr->foraStackData;
    return tempStackData;
}

void foraStackLinkedList::pushStack(int data)
{
    this->stackHead->foraStackData = data;
    foraStackLinkedListStructure* stackHead = new foraStackLinkedListStructure();
    this->stackHead->tailNode =  stackHead;
}