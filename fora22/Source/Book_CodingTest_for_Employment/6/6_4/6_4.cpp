#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> sliceArrayComposedString(string sLine) {
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

vector<int> sliceArrayComposedInt(string sLine) {
	int previous = 0;
	int current = 0;
	vector<int> resultSliceString;

	current = sLine.find(" ");
	while (current != string::npos) {
		string substring = sLine.substr(previous,	current - previous);
		resultSliceString.push_back(stoi(substring));
		previous = current + 1;
		current = sLine.find(" ", previous);
	}
	resultSliceString.push_back(stoi(sLine.substr(previous, current - previous)));
	// slice end

	return resultSliceString;
}


int solve(ifstream* readFile) {
	string getInfo;
	vector<string>* nk = new vector<string>;
	int n, k;
	if ((*readFile).is_open()) {
		getline(*readFile, getInfo);
		*nk = sliceArrayComposedString(getInfo);
	}
	n = stoi((*nk)[0]);
	k = stoi((*nk)[1]);
	delete nk;

	// Get Array
	getline(*readFile, getInfo);
	vector<int> arrayA = sliceArrayComposedInt(getInfo);
	getline(*readFile, getInfo);
	vector<int> arrayB = sliceArrayComposedInt(getInfo);

	int min, max;
	vector<int>::iterator it;
	// Get Minimum Data in arrayA
	for (int i = 0; i < k; i++) {
		min = *min_element(arrayA.begin(), arrayA.end());
		max = *max_element(arrayB.begin(), arrayB.end());

		// remove() function can't delete vector size.
		// size still exist, it just overwirte data from delete data
		// So, if you want delete data & size, you should use erase() function too.
		//arrayA.erase(remove(arrayA.begin(), arrayA.end(), min));
		//arrayB.erase(remove(arrayB.begin(), arrayB.end(), max));

		it = find(arrayA.begin(), arrayA.end(), min);
		*it = max;
		it = find(arrayB.begin(), arrayB.end(), max);
		*it = min;
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = result + arrayA[i];
	}

	return result;
}

int main(void) {

	ifstream readfile("input.txt");
	
	cout << solve(&readfile);

	return 0;
}