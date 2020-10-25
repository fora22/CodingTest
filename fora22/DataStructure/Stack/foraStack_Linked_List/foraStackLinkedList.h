//
// Created by fora2 on 2020-10-24.
//

#ifndef FORASTACK_LINKED_LIST_FORASTACKLINKEDLIST_H
#define FORASTACK_LINKED_LIST_FORASTACKLINKEDLIST_H


//#include "foraStackLinkedListStructure.h"  DELETE
#include <iostream>

using namespace std;

class foraStackLinkedList {
private:
//    foraStackLinkedListStructure* stackHead;
    int foraStackData;
    int foraStackUsed;
    foraStackLinkedList* foraStackTail;
public:
    foraStackLinkedList();
    ~foraStackLinkedList();
    int& operator[] (int index);
    void pushStack(int data);
    int outputStack();
    int length();
    int peek();
};


#endif //FORASTACK_LINKED_LIST_FORASTACKLINKEDLIST_H
