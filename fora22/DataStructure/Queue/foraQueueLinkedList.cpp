//
// Created by fora2 on 2020-10-24.
//

#include "foraQueueLinkedList.h"

foraQueueLinkedList::foraQueueLinkedList() {
    foraQueueLinkedList *nextQueue = new foraQueueLinkedList;
    head = nullptr;
    tail = nextQueue;
    lastListPtr = nextQueue;
    firstListPtr = nextQueue;
    used = 0;
}

foraQueueLinkedList::~foraQueueLinkedList() {
    foraQueueLinkedList *findQueuePtr = this;
    foraQueueLinkedList *forDelQueuePtr;
    for (int i = 0; i < (used); i++) {
        forDelQueuePtr = findQueuePtr->tail;
        delete findQueuePtr;
        findQueuePtr = forDelQueuePtr;
    }
}

int &foraQueueLinkedList::operator[](int index) {
    foraQueueLinkedList *findDataPtr = this;

    for (int i = 0; i < (index + 1); i++) {
        findDataPtr = findDataPtr->tail;
    }

    return findDataPtr->data;
}

void foraQueueLinkedList::push(int data) {
    // REVIEW - Queue Linked List는 끝에 data가 비어있는 list가 있음, lastListPtr 끝에 비어있는 list를 가리키는 포인터 변수
    foraQueueLinkedList *nextQueue = new foraQueueLinkedList;
    lastListPtr->data = data;
    lastListPtr->tail = nextQueue;
    nextQueue->tail = nullptr;
    nextQueue->head = lastListPtr;
    lastListPtr = nextQueue;
    used++;
}

int foraQueueLinkedList::output() {
    int output = firstListPtr->data;
    foraQueueLinkedList *deleteQueuePtr = this->tail;
    this->tail = deleteQueuePtr->tail;
    delete deleteQueuePtr;
    used--;

    return output;
}

int foraQueueLinkedList::length() {
    return used;
}