#include "foraStackLinkedList.h"

int main() {
    const int s_size = 5;
    foraStackLinkedList *newStack = new foraStackLinkedList;
    for (int i = 0; i < s_size; i++) {
        newStack->pushStack(i);
    }
    // int out = newStack->outputStack();
    int temp;
    for (int i = 0; i < s_size; i++) {
        temp = (*newStack)[i];
        cout << temp << endl;
    }
    return 0;
}
