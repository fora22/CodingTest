#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int getMaxElement(vector<int> inputArray) {
	int maxValue = *max_element(inputArray.begin(), inputArray.end());

	return maxValue;
}

int riceCakesInBinarySearch(vector<int> inputArray, const int arraySize, vector<int> _riceCakes, int m) {
	int middleIndex = -1;
	int startIndex = 0;
	int endIndex = arraySize - 1;
	vector<int> result;
	int sum;

	while (endIndex - startIndex >= 0) {
		middleIndex = (startIndex + endIndex) / 2;
		sum = 0;
		for (int i = 0; i < _riceCakes.size(); i++) {
			if (_riceCakes[i] - middleIndex > 0) {
				sum = sum + _riceCakes[i] - middleIndex;
			}
		}
		
		if (sum >= m) {
			result.push_back(middleIndex);
			startIndex = middleIndex + 1;
		} else {
			endIndex = middleIndex - 1;
		}
	}
	int maxHeight = getMaxElement(result);

	return maxHeight;
}
vector<int> sliceArrayComposedInt(string sLine) {
	int previous = 0;
	int current = 0;
	vector<int> resultSliceString;

	current = sLine.find(" ");
	while (current != string::npos) {
		string substring = sLine.substr(previous, current - previous);
		resultSliceString.push_back(stoi(substring));
		previous = current + 1;
		current = sLine.find(" ", previous);
	}
	resultSliceString.push_back(stoi(sLine.substr(previous, current - previous)));
	// slice end

	return resultSliceString;
}

int solve(ifstream* readFile) {
	int result;
	int N, M;
	string getInfo;
	vector<int> riceCakes;

	if ((*readFile).is_open()) {
		getline(*readFile, getInfo);
		N = getInfo[0] - '0';
		M = getInfo[2] - '0';
		

		getline(*readFile, getInfo);
		riceCakes = sliceArrayComposedInt(getInfo);
	}

	int maxRiceCakesLength = getMaxElement(riceCakes);
	vector<int> riceArray(maxRiceCakesLength);
	for (int i = 1; i < (maxRiceCakesLength + 1); i++) {
		riceArray[i - 1] = i;
	}
	
	result = riceCakesInBinarySearch(riceArray, riceArray.size(), riceCakes, M);

	return result;
}

int main(void) {

	ifstream readfile("input.txt");
	
	int solveProblem = solve(&readfile);

	cout << solveProblem << endl;

	return 0;
}