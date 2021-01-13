#include <iostream>
#include <vector>
#include <string>

using namespace std;

int SequentialSearch(vector<int> inputArray, const int arraySize, const int findData);

int main(void) {
	vector<int> v{ 1, 3, 4, 7, 8, 13, 17 };

	int result;
	result = SequentialSearch(v, v.size(), 8);
	cout << result << endl;
	

	return 0;
}

int SequentialSearch(vector<int> inputArray, const int arraySize, const int findData) {
	// argument (vector, vector Å©±â, Ã£´Â µ¥ÀÌÅÍ)
	int middleIndex = -1;
	
    for (int i = 0; i < arraySize; i++) {
        if (findData == inputArray[i]) {
            middleIndex = i;
            break;
        }
    }

    return middleIndex;
}