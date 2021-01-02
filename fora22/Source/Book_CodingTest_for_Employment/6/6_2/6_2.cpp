#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(ifstream* readFile) {
	string getInfo;
	int arraySize;
	if ((*readFile).is_open()) {
		getline(*readFile, getInfo);
		arraySize = stoi(getInfo);		// string  to int
	}
	vector<int> randArray(arraySize);

	for (int i = 0; i < arraySize; i++) {
		getline(*readFile, getInfo);
		randArray[i] = stoi(getInfo);
	}
	
	sort(randArray.begin(), randArray.end());		// STL sort is composed by Quick Sort. If you want sort descending, add `greater<int>()` at last parameter.

	return randArray;
}

int main(void) {

	ifstream readfile("input.txt");
	vector<int> result = solve(&readfile);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}