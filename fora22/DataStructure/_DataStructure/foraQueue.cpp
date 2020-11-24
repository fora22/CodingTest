//
// Created by Assistant_2 on 2020-11-16.
//

#include "foraQueue.h"

foraQueue::foraQueue() {
    foraNode *newNode = new foraNode();
    firstListPtr = newNode;
    lastListPtr = newNode;
    used = 0;
}

foraQueue::foraQueue(int data) {
    if (data > 0) {
        for (int i = 0; i < data; i++) {
            foraNode *newNode = new foraNode();
            lastListPtr->tail = newNode;
            lastListPtr = newNode;
            lastListPtr->data = i;
            used++;
        }
    } else {
        cout << "Index out of range" << endl;
    }

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
    if (used > 0){
    int dequeue = firstListPtr->data;
    foraNode *delQueuePtr = firstListPtr->tail;
    firstListPtr->tail = delQueuePtr->tail;
    delete delQueuePtr;
    used--;

    return dequeue;

    } else {
        cout << "There is no data" << endl;
        return -1;
    }
}

int foraQueue::length() {
    return used;
}