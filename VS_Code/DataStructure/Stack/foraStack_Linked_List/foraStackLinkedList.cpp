#include "foraStackLinkedList.h"




// foraStackLinkedList::~foraStackLinkedList() {
//     delete[] stackArray;
// }

int& foraStackLinkedList::operator[] (int index) 
{
    foraStackLinkedListStructure* findDataPtr = this->stackHead;
    int tempStackData;
    if (index == 0) {
        tempStackData = findDataPtr->foraStackData;
    } else
    {
        for (int i = 0; i < index; i++) {
            findDataPtr = findDataPtr->tailNode;
        }
        tempStackData = findDataPtr->foraStackData;
    }

    return tempStackData;
}

void foraStackLinkedList::pushStack(int data) 
{
    this->stackHead->foraStackData = data;
    foraStackLinkedListStructure* stackHead = new foraStackLinkedListStructure;
    this->stackHead->tailNode =  stackHead;
}


//REVIEW main함수는 확인용으로 만듬
int main(void)
{
    const int s_size = 5;
    foraStackLinkedList *newStack = new foraStackLinkedList(s_size);
    for (int i = 0; i < s_size; i++) {
        newStack->pushStack(i);
    }
    // int out = newStack->outputStack();
    int temp;
    for (int i = 0; i < s_size; i++) {
        temp = newStack[i];
        cout << temp << endl;
    }
    return 0;
}