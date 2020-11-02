//
// Created by fora2 on 2020-10-24.
//

#include "foraStackLinkedList.h"

foraStackLinkedList::foraStackLinkedList() {
    foraStackHead = nullptr;
    foraStackTail = nullptr;
    foraStackEndTail = this;
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
    // REVIEW - Stack Linked List는 끝에 data가 비어있는 list가 있음, foraStakcEndTail은 끝에 비어있는 list를 가리키는 포인터 변수
    foraStackLinkedList *nextStack = new foraStackLinkedList;
    foraStackEndTail->foraStackData = data;
    foraStackEndTail->foraStackTail = nextStack;
    nextStack->foraStackTail = nullptr;
    nextStack->foraStackHead = foraStackEndTail;
    foraStackEndTail = nextStack;
    foraStackUsed++;
}

int foraStackLinkedList::outputStack() {
    foraStackLinkedList *deleteStackPtr = foraStackEndTail;
    int output = foraStackEndTail->foraStackHead->foraStackData;
    foraStackEndTail = foraStackEndTail->foraStackHead;
    delete deleteStackPtr;
    foraStackEndTail->foraStackTail = nullptr;
    foraStackUsed--;

    return output;
}

int foraStackLinkedList::length() {
    return foraStackUsed;
}

int foraStackLinkedList::peek() {
    return foraStackEndTail->foraStackHead->foraStackData;
}