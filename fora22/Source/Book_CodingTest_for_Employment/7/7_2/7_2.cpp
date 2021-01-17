#include <iostream>	
#include <fstream>
#include <string>
#include <vector>


using namespace std;

int BinarySearch(vector<int> inputArray, const int arraySize, const int findData) {
	int middleIndex;
	int startIndex = 0;
	int endIndex = arraySize - 1;

	while (endIndex - startIndex >= 0) {
		middleIndex = (startIndex + endIndex) / 2;
		if (inputArray[middleIndex] == findData) {
			return middleIndex;
		}

		if (inputArray[middleIndex] < findData) {
			startIndex = middleIndex + 1;
		} else {
			endIndex = middleIndex - 1;
		}
	}
	return -1;
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

vector<int> solve(ifstream* readFile) {
	vector<int> result;
	int N, M;
	string getInfo;
	vector<int> allParts, orderParts;

	if ((*readFile).is_open()) {
		getline(*readFile, getInfo);
		N = stoi(getInfo);

		getline(*readFile, getInfo);
		allParts = sliceArrayComposedInt(getInfo);

		getline(*readFile, getInfo);
		M = stoi(getInfo);

		getline(*readFile, getInfo);
		orderParts = sliceArrayComposedInt(getInfo);
	}
	
	for (int i = 0; i < orderParts.size(); i++) {
		result.push_back(BinarySearch(allParts, allParts.size(), orderParts[i]));
	}


	return result;
}

int main(void) {

	ifstream readfile("input.txt");
	
	vector<int> solveProblem = solve(&readfile);
	vector<bool> isPartsHere(solveProblem.size());

	for (int i = 0; i < solveProblem.size(); i++) {
		if (solveProblem[i] >= 0) {
			cout << "yes ";
		} else {
			cout << "no ";
		}
	}

	return 0;
}