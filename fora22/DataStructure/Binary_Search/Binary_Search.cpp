#include <iostream>
#include <vector>
#include <string>

using namespace std;

int BinarySearch(vector<int> inputArray, const int arraySize, const int findData);

int main(void) {
	vector<int> v{ 1, 3, 4, 7, 8, 13, 17 };

	int result;
	result = BinarySearch(v, v.size(), 8);
	cout << result << endl;
	

	return 0;
}

int BinarySearch(vector<int> inputArray, const int arraySize, const int findData) {
	// argument (vector, vector Å©±â, Ã£´Â µ¥ÀÌÅÍ)
	int middleIndex;
	int startIndex = 0;
	int endIndex = arraySize - 1;
	
	while (endIndex - startIndex >= 0)
	{
		middleIndex = (startIndex + endIndex) / 2;
		if (inputArray[middleIndex] == findData) {
			return middleIndex; // return index
		}
		
		if (inputArray[middleIndex] < findData) {
			startIndex = middleIndex + 1;
		}
		else {
			endIndex = middleIndex - 1;
		}
	}
	return -1;
}