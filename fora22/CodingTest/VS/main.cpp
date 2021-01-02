#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second < b.second) { // If left bigger than right, it is ascending. If right bigger than left, it is descending.
		return true;
	} else {
		return false;
	}
}

vector<string> sliceString(string sLine) {
	int previous = 0;
	int current = 0;
	vector<string> resultSliceString;

	current = sLine.find(" ");
	while (current != string::npos) {
		string substring = sLine.substr(previous, current - previous);
		resultSliceString.push_back(substring);
		previous = current + 1;
		current = sLine.find(" ", previous);
	}
	resultSliceString.push_back(sLine.substr(previous, current - previous));
	// slice end

	return resultSliceString;
}

vector<pair<string, int>> solve(ifstream* readFile) {
	string getInfo;
	int arraySize;
	if ((*readFile).is_open()) {
		getline(*readFile, getInfo);
		arraySize = stoi(getInfo);		// string  to int
	}

	vector<pair<string, int>> result;
	for (int i = 0; i < arraySize; i++) {
		getline(*readFile, getInfo);
		vector<string>* dataStrPtr = new vector<string>;
		(*dataStrPtr) = sliceString(getInfo);

		result.push_back(make_pair((*dataStrPtr)[0], stoi((*dataStrPtr)[1])));
		delete dataStrPtr;
	}

	sort(result.begin(), result.end(), compare);	// STL sort is composed by Quick Sort. If you want sort descending, add `greater<int>()` at last parameter.

	return result;
}

int main(void) {

	ifstream readfile("input.txt");
	vector<pair<string, int>> result = solve(&readfile);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i].first << " ";
	}

	return 0;
}