#include "foraStackLinkedList.h"

int main() {
    const int s_size = 5;
    foraStackLinkedList *newStack = new foraStackLinkedList;
    for (int i = 0; i < s_size; i++) {
        newStack->pushStack(i);
    }

    for (int i = 0; i < s_size; i++) {
        cout << (*newStack)[i]  << endl;
    }
    cout << "길이 : " << newStack->length() << " peek : " << newStack->peek() << endl;
    int out = newStack->outputStack();
    cout << "빠져나온 값 : " << out << " peek : " << newStack->peek() << endl;

    return 0;
}
