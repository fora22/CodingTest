//
// Created by Assistant_2 on 2020-10-22.
//

#ifndef FORASTACKLINKEDLIST_FORASTACKLINKEDLIST_H
#define FORASTACKLINKEDLIST_FORASTACKLINKEDLIST_H

#include <iostream>
#include "foraStackLinkedListStructure.h"

using namespace std;

class foraStackLinkedList {
private:
    foraStackLinkedListStructure* stackHead = new foraStackLinkedListStructure;
public:
    foraStackLinkedList();
    foraStackLinkedList(int size);
    ~foraStackLinkedList();
    int& operator[] (int index);
    void pushStack(int data);
    int outputStack();
    int length();
    int peek();
};

#endif //FORASTACKLINKEDLIST_FORASTACKLINKEDLIST_H




