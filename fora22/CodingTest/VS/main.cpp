#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getMin(vector<int> inputArray) {
	int minValue = *min_element(inputArray.begin(), inputArray.end());

	return minValue;
}

vector<int> sliceArrayComposedInt(string sLine) {
	int previous = 0;
	int current = 0;
	vector<int> resultSliceInt;

	current = sLine.find(" ");
	while (current != string::npos) {
		string substring = sLine.substr(previous, current - previous);
		resultSliceInt.push_back(stoi(substring));
		previous = current + 1;
		current = sLine.find(" ", previous);
	}
	resultSliceInt.push_back(stoi(sLine.substr(previous, current - previous)));
	// slice end

	return resultSliceInt;
}

vector<int> solve(ifstream* readFile) {
	vector<int> result;
	int N, M;
	vector<int> readInfo;
	string getInfo;
	vector<int> moneyCase;

	if ((*readFile).is_open()) {
		getline(*readFile, getInfo);
		readInfo = sliceArrayComposedInt(getInfo);
		N = readInfo[0];
		M = readInfo[1];

		for (int i = 0; i < N; i++) {
			getline(*readFile, getInfo);
			moneyCase.push_back(stoi(getInfo));
		}
	}

	vector<int> dpTable(M + 1, 10001);
	vector<int> minVec(2);
	dpTable[0] = 0;

	for (int i = 0; i < moneyCase.size(); i++) {
		for (int j = moneyCase[i]; j < (M + 1); j++) {
			if ((dpTable[j - moneyCase[i]]) != 10001) {
				minVec[0] = dpTable[j];
				minVec[1] = dpTable[j - moneyCase[i]] + 1;
				dpTable[j] = getMin(minVec);
			}
		}
	}

	if (dpTable[M] != 10001) {
		result.push_back(dpTable[M]);
	} else {
		result.push_back(-1);
	}


	return result;
}

int main(void) {

	ifstream readfile("input.txt");

	vector<int> solveProblem = solve(&readfile);


	cout << solveProblem[0] << endl;

	return 0;
}