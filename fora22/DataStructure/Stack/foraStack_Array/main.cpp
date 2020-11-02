#include <iostream>
#include "foraStackArray.h"

int main() {
    const int s_size = 10;
    foraStackArray* newStack = new foraStackArray(s_size);
    for (int i = 0; i < s_size; i++) {
        newStack->pushStack(i);
    }
    for (int i = 0; i < s_size; i++) {
        cout << newStack->stackArray[i] << endl;
    }

    int out = newStack->outputStack();

    cout << "쓰레기 값 : " << newStack->stackArray[9] << endl;

    cout << "제거된 값은 " << out << endl;

    return 0;
}
