//
// Created by fora2 on 2020-10-24.
//

#include "foraStackLinkedList.h"

foraStackLinkedList::foraStackLinkedList() {
    foraStackTail = nullptr;
    foraStackUsed = 0;
}

foraStackLinkedList::~foraStackLinkedList() {
    foraStackLinkedList *findStackPtr = this;
    foraStackLinkedList *forDelStackPtr;
    for (int i = 0; i < (foraStackUsed-1); i++) {
        forDelStackPtr = findStackPtr->foraStackTail;
        delete findStackPtr;
        findStackPtr = forDelStackPtr;
    }
}

int &foraStackLinkedList::operator[](int index) {
    foraStackLinkedList *findDataPtr = this;

    for (int i = 0; i < index; i++) {
        findDataPtr = findDataPtr->foraStackTail;
    }

    return findDataPtr->foraStackData;
}

void foraStackLinkedList::pushStack(int data) {
    foraStackLinkedList *findStackPtr = this;
    for (int i = 0; i < foraStackUsed; i++) {
        findStackPtr = findStackPtr->foraStackTail;
    }
    findStackPtr->foraStackData = data;
    foraStackLinkedList *nextStack = new foraStackLinkedList;
    nextStack->foraStackTail = findStackPtr->foraStackTail;
    findStackPtr->foraStackTail = nextStack;
    foraStackUsed++;
}

int foraStackLinkedList::outputStack() {
    foraStackLinkedList *findStackPtr = this;
    for (int i = 0; i < (foraStackUsed-2); i++) {
        findStackPtr = findStackPtr->foraStackTail;
    }
    int output = findStackPtr->foraStackTail->foraStackData;
    delete findStackPtr->foraStackTail;
    findStackPtr->foraStackTail = nullptr;
    foraStackUsed--;

    return output;
}

int foraStackLinkedList::length() {
    return foraStackUsed;
}

int foraStackLinkedList::peek() {
    foraStackLinkedList *findDataPtr = this;

    for (int i = 0; i < (foraStackUsed-1); i++) {
        findDataPtr = findDataPtr->foraStackTail;
    }

    return findDataPtr->foraStackData;
}