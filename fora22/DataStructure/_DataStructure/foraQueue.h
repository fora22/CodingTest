//
// Created by Assistant_2 on 2020-11-16.
//

#ifndef _DATASTRUCTURE_FORAQUEUE_H
#define _DATASTRUCTURE_FORAQUEUE_H
#include <iostream>
#include "foraNode.h"
using namespace std;

class foraQueue {
private:
    int used;
    foraNode* lastListPtr;
    foraNode* firstListPtr;
public:
    foraQueue();
    ~foraQueue();
    int& operator[] (int index);
    void enqueue(int data);
    int dequeue();
    int length();

};


#endif //_DATASTRUCTURE_FORAQUEUE_H
