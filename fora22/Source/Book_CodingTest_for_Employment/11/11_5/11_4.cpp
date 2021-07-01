#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sliceArrayComposedInt(string sLine);

int main(void) {
	ifstream readFile("input.txt");
	string getData;
	int N, M;
	vector<int> weights;

	if (readFile.is_open()) {
		getline(readFile, getData);
		vector<int> nm;
		nm = sliceArrayComposedInt(getData);
		N = nm[0];
		M = nm[1];

		getline(readFile, getData);
		weights = sliceArrayComposedInt(getData);
	}

	int ballCount = 0;
	
	for (int i = 0; i < (weights.size() - 1); i++) {
		for (int j = i; j < weights.size(); j++) {
			if (weights[i] != weights[j]) {
				ballCount += 1;
			}
		}
	}

	cout << ballCount << endl;

	return 0;
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