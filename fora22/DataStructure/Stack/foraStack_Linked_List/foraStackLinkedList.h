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
    foraStackLinkedList* head;
    foraStackLinkedList* tail;
    foraStackLinkedList* lastListTail;
public:
    foraStackLinkedList();
    ~foraStackLinkedList();
    int& operator[] (int index);
    void push(int data);
    int output();
    int length();
    int peek();
};


#endif //FORASTACK_LINKED_LIST_FORASTACKLINKEDLIST_H
