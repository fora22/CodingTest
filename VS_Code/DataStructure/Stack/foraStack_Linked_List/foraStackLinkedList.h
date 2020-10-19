#include <iostream>
#include "foraStackLinkedListStructure.h"

using namespace std;

class foraStackLinkedList
{
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