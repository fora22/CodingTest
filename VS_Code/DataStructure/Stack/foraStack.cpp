#include "foraStack.h"

foraStack::foraStack() : stackSize(1), stackUsed(0) {
    stackArray = new int[stackSize];
}

foraStack::foraStack(int size)  : stackSize(size), stackUsed(0) {
    stackArray = new int[stackSize];
}

foraStack::~foraStack() {
    delete[] stackArray;
}

int& foraStack::operator[] (int index) {
    //REVIEW - operator를 사용하면 array[5] 형식으로 배열 인덱스로 데이터를 접근할 수 있다.
    return this->stackArray[index];
}

void foraStack::pushStack(int data) {
    if (this->stackUsed < this->stackSize) {
        //REVIEW - 지금 사용하는공간이 크기보다 작으면 초기화 시킴
        this->stackArray[this->stackUsed] = data;
    }
    else {
        //REVIEW - 클 경우 1칸을 더 늘려서 초기화 시킴
        int* temp = new int[this->stackSize];
        for (int i = 0; i < this->stackUsed; i++) {
            temp[i] = this->stackArray[i];
        }

        delete[] this->stackArray;
        this->stackSize += 1;
        this->stackArray = new int[stackSize];

        for (int i = 0; i < this->stackUsed; i++) {
            this-> stackArray[i] = temp[i];
        }
        delete[] temp;
        this->stackArray[this->stackUsed] = data;
    }
    
    this->stackUsed++;
}

int foraStack::outputStack() {
    if (this->stackUsed == 0) {
        return -1;
    }
    int output = this->stackArray[this->stackUsed - 1];     //REVIEW - output 변수에 stack 제일 나중에 들어온 값을 저장함
    this->stackUsed--;
    int* temp = new int[this->stackUsed];
    for (int i = 0; i < this->stackUsed; i++) {
        temp[i] = this->stackArray[i];
    }
    delete[] this->stackArray;
    
    this->stackArray = new int[this->stackUsed];
    for(int i = 0; i < this->stackUsed; i++) {
        this->stackArray[i] =  temp[i];
    }
    delete[] temp;

    return output;
}

int foraStack::length() {
    return this->stackSize;
}

int foraStack::peek() {
    return this->stackArray[stackUsed];
}

//REVIEW main함수는 확인용으로 만듬
int main(void)
{
    const int s_size = 10;
    foraStack *newStack = new foraStack(s_size);
    for (int i = 0; i < s_size; i++) {
        newStack->pushStack(i);
    }
    int out = newStack->outputStack();

    for (int i = 0; i < s_size; i++) {
        cout << newStack->stackArray[i] << endl;
    }
    cout << out << endl;
    return 0;
}