//
// Created by Assistant_2 on 2020-11-16.
//

#include "foraQueue.h"

foraQueue::foraQueue() {
    foraNode *newNode = new foraNode();
    newNode->tail = nullptr;
    firstListPtr = newNode;
    lastListPtr = newNode;
    used = 0;
}

foraQueue::~foraQueue() {
    foraNode *findQueuePtr = firstListPtr;
    foraNode *forDelQueuePtr;
    for (int i = 0; i < used; ++i) {
        forDelQueuePtr = findQueuePtr->tail;
        delete findQueuePtr;
        findQueuePtr = forDelQueuePtr;
    }
    delete firstListPtr;
}

int &foraQueue::operator[](int index) {
    if ((index >= 0) && (index <= used)) {
        foraNode *findDataPtr = firstListPtr;
        for (int i = 0; i < (index + 1); i++) {
            findDataPtr = findDataPtr->tail;
        }

        return findDataPtr->data;
    } else {
        int errorNumber = 1;
        cout << "Index out of range" << endl;
        return errorNumber;
    }
}

void foraQueue::enqueue(int data) {
    foraNode *newNode = new foraNode;
    lastListPtr->tail = newNode;
    lastListPtr = newNode;
    lastListPtr->data = data;
    used++;
}

int foraQueue::dequeue() {
    int dequeue = firstListPtr->data;
    foraNode *delQueuePtr = firstListPtr->tail;
    firstListPtr->tail = delQueuePtr->tail;
    delete delQueuePtr;
    used--;

    return dequeue;
}

int foraQueue::length() {
    return used;
}