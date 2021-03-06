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
    int n;
    string getInfo;
    vector<int> foodWareHouse;


    if((*readFile).is_open()) {
        getline(*readFile, getInfo);
        n = stoi(getInfo);
        getline(*readFile, getInfo);
        foodWareHouse = sliceArrayComposedInt(getInfo);
    }

    vector<int> dpTable(100);     // Dinamic Programing Table
    vector<int> compareVector(2); // max element 를 위한 vector
    dpTable[0] = foodWareHouse[0];

    compareVector[0] = dpTable[0];
    compareVector[1] = dpTable[1];

    dpTable[1] = getMaxElement(compareVector); // get Max element

    for (int i = 0; i < n; i++) {
        compareVector[0] = dpTable[i - 1]; // 이전 값
        compareVector[1] = dpTable[i - 2] + foodWareHouse[i]; // 현재 값과 2개 뒤의 값을 합친 값
        dpTable[i] = getMaxElement(compareVector); // get Max element : 둘 중에 제일 큰 값을 저장
    }
    
    result.push_back(dpTable[n - 1]);

    return result;
}


int main(void) {
    ifstream readfile("input.txt");
	
	vector<int> solveProblem = solve(&readfile);
	
	cout << solveProblem[0] << endl;

    return 0;
}
