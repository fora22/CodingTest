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

vector<int> solve(ifstream* readFile) {
	vector<int> result;
	int n;
	string getInfo;
	
	if ((*readFile).is_open()) {
		getline(*readFile, getInfo);
		n = stoi(getInfo);
	}

	vector<int> dpTable(n + 1);
	vector<int> getMinValue(2);

	
	for (int i = 2; i < (n + 1); i++) {
		dpTable[i] = dpTable[i - 1] + 1;

		if ((i % 2) == 0) {
			getMinValue[0] = dpTable[i];
			getMinValue[1] = dpTable[i / 2] + 1;
			dpTable[i] = getMin(getMinValue);
		}

		if ((i % 3) == 0) {
			getMinValue[0] = dpTable[i];
			getMinValue[1] = dpTable[i / 3] + 1;
			dpTable[i] = getMin(getMinValue);
		}


		if (i % 5 == 0) {
			getMinValue[0] = dpTable[i];
			getMinValue[1] = dpTable[i / 5] + 1;
			dpTable[i] = getMin(getMinValue);
		}
	}

	result.push_back(dpTable[n]);

	return result;
}

int main(void) {

	ifstream readfile("input.txt");
	
	vector<int> solveProblem = solve(&readfile);
	
	cout << solveProblem[0] << endl;

	return 0;
}