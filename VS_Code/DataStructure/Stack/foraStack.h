#include <iostream>

using namespace std;

class foraStack
{
private:
    int stackSize;
    int stackUsed;
public:
    int* stackArray;
    foraStack();
    foraStack(int size);
    ~foraStack();
    int &operator[] (int index);
    void pushStack(int data);
    int outputStack();
    int length();
};