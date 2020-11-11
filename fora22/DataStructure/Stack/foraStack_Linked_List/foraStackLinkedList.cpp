//
// Created by fora2 on 2020-10-24.
//

#include "foraStackLinkedList.h"

foraStackLinkedList::foraStackLinkedList() {
    head = nullptr;
    tail = nullptr;
    lastListTail = this;
    foraStackUsed = 0;
}

foraStackLinkedList::~foraStackLinkedList() {
    foraStackLinkedList *findStackPtr = this;
    foraStackLinkedList *forDelStackPtr;
    for (int i = 0; i < (foraStackUsed-1); i++) {
        forDelStackPtr = findStackPtr->tail;
        delete findStackPtr;
        findStackPtr = forDelStackPtr;
    }
}

int &foraStackLinkedList::operator[](int index) {
    foraStackLinkedList *findDataPtr = this;

    for (int i = 0; i < index; i++) {
        findDataPtr = findDataPtr->tail;
    }

    return findDataPtr->foraStackData;
}

void foraStackLinkedList::push(int data) {
    // REVIEW - Stack Linked List는 끝에 data가 비어있는 list가 있음, foraStakcEndTail은 끝에 비어있는 list를 가리키는 포인터 변수
    foraStackLinkedList *nextStack = new foraStackLinkedList;
    lastListTail->foraStackData = data;
    lastListTail->tail = nextStack;
    nextStack->tail = nullptr;
    nextStack->head = lastListTail;
    lastListTail = nextStack;
    foraStackUsed++;
}

int foraStackLinkedList::output() {
    foraStackLinkedList *deleteStackPtr = lastListTail;
    int output = lastListTail->head->foraStackData;
    lastListTail = lastListTail->head;
    delete deleteStackPtr;
    lastListTail->tail = nullptr;
    foraStackUsed--;

    return output;
}

int foraStackLinkedList::length() {
    return foraStackUsed;
}

int foraStackLinkedList::peek() {
    return lastListTail->head->foraStackData;
}