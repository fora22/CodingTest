//
// Created by fora2 on 2020-10-24.
//

#ifndef FORASTACK_LINKED_LIST_FORASTACKLINKEDLIST_H
#define FORASTACK_LINKED_LIST_FORASTACKLINKEDLIST_H

#include "foraStackLinkedListStructure.h"

using namespace std;

class foraStackLinkedList {
private:
    foraStackLinkedListStructure* stackHead;
public:
    foraStackLinkedList();
    // foraStackLinkedList(int size);
    // ~foraStackLinkedList();
    int& operator[] (int index);
    void pushStack(int data);
    // int outputStack();
    // int length();
    // int peek();
};


#endif //FORASTACK_LINKED_LIST_FORASTACKLINKEDLIST_H
