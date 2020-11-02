#include <iostream>

using namespace std;

int main() {
    int* array = new int[5];
    for (int i = 0; i < 5; i++) {
        array[i] = i;
    }
    int* temp = new int [4];
    for (int i = 0; i < 4; i++) {
        temp[i] = array[i];
    }

    delete [] array;

    cout << array <<" & " << &array << endl;

    for (int i = 0; i < 4; i++) {
        array[i] = temp[i];
    }

    for (int i = 0; i < 5; i++) {
        cout << array[i] << endl;
    }



    return 0;
}
