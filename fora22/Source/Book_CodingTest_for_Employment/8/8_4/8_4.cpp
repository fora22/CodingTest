#include <iostream>	
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> solve(ifstream* readFile) {
	vector<int> result;
	int n;
	string getInfo;

	if ((*readFile).is_open()) {
		getline(*readFile, getInfo);
		n = stoi(getInfo);
	}

	vector<int> dpTable(n);

	dpTable[0] = 1;
	dpTable[1] = 3;

	for (int i = 2; i < dpTable.size(); i++) {
		dpTable[i] = dpTable[i - 1] + (dpTable[i - 2] * 2);
	}
	
	result.push_back(dpTable[n - 1] % 796796);


	return result;
}

int main(void) {

	ifstream readfile("input.txt");
	
	vector<int> solveProblem = solve(&readfile);
	

	cout << solveProblem[0] << endl;

	return 0;
}