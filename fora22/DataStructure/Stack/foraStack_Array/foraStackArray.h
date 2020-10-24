//
// Created by fora2 on 2020-10-24.
//

#ifndef FORASTACK_ARRAY_FORASTACKARRAY_H
#define FORASTACK_ARRAY_FORASTACKARRAY_H

#include <iostream>

using namespace std;

class foraStackArray {
private:
    int stackSize;
    int stackUsed;
public:
    int* stackArray;
    foraStackArray();
    foraStackArray(int size);
    ~foraStackArray();
    int& operator[] (int index);
    void pushStack(int data);
    int outputStack();
    int length();
    int peek();
};


#endif //FORASTACK_ARRAY_FORASTACKARRAY_H
