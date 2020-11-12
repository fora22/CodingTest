//
// Created by fora2 on 2020-10-24.
//

#ifndef FORAQUEUE_LINKED_LIST_FORAQUEUELINKEDLIST_H
#define FORAQUEUE_LINKED_LIST_FORAQUEUELINKEDLIST_H

#include <iostream>

using namespace std;

class foraQueueLinkedList {
private:
    int data;
    int used;
    foraQueueLinkedList* head;
    foraQueueLinkedList* tail;
    foraQueueLinkedList* lastListPtr;
    foraQueueLinkedList* firstListPtr;
public:
    foraQueueLinkedList();
    ~foraQueueLinkedList();
    int& operator[] (int index);
    void push(int data);
    int output();
    int length();
};


#endif //FORASTACK_LINKED_LIST_FORASTACKLINKEDLIST_H
