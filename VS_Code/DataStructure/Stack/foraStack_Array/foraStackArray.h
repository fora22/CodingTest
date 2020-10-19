#include <iostream>

using namespace std;

class foraStackArray
{
private:
    int stackSize;
    int stackUsed;
public:
    int* stackArray;
    foraStackArray();
    foraStackArray(int size);
    ~foraStackArray();
    int &operator[] (int index);
    void pushStack(int data);
    int outputStack();
    int length();
    int peek();
};