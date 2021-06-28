#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sliceArrayComposedInt(string sLine);
bool compare(int a, int b);

int main(void) {
	ifstream readFile("input.txt");
	string getData;
	int N;
	vector<int> coins;

	if (readFile.is_open()) {
		getline(readFile, getData);
		N = getData[0] - '0';

		getline(readFile, getData);
		
		coins = sliceArrayComposedInt(getData);
	}

	int target = 1;
	sort(coins.begin(), coins.end(), compare);
	
	for (int i = 0; i < coins.size(); i++) {
		if (target < coins[i]){
			break;
		}
		target += coins[i];
	}

	cout << target << endl;

	return 0;
}

bool compare(int a, int b) {
	return a < b;
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