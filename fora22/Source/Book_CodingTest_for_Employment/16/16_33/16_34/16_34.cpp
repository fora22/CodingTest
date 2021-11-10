#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
vector<int> sliceArrayComposedInt(string sLine);	// 입력받은 문자열을 vector로 변환해주는 함수
int getMaxValue(int a, int b);						// 두 값중 어떤 것이 더 큰지 구해주는 함수
int getMaxElement(vector<int> inputArray);			// vector에서 최댓값을 구해주는 함수 

int main(void) {
	// ifstream readfile("input.txt");
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N = 0;
	string getInfo;
	vector<int> getData;
	vector<vector<int>> schedule = { {-1, -1} };

	const int dayTerm =	0;		// 상담 기간 index
	const int price = 1;		// 상담료 index

	/*if (readfile.is_open()) {
	}*/
		// getline(readfile, getInfo);
		// N = stoi(getInfo);
	cin >> N;
		

	for (int i = 0; i < N; i++) {
		// getline(readfile, getInfo);
		cin >> getInfo;
		getData = sliceArrayComposedInt(getInfo);
		schedule.push_back(getData);
	}


	vector<int> dpTable(15 + 5);
	int getMoney = 0;
	int next_idx = 0;

	for (int i = 1; i < N + 1; i++) {
		getMoney = getMaxValue(getMoney, dpTable[i]);
		next_idx = i + schedule[i][dayTerm];
		dpTable[next_idx] = getMaxValue(dpTable[next_idx], getMoney + schedule[i][price]);
	}

	vector<int>::iterator iter;
	vector<int> result = vector<int>(dpTable.begin(), dpTable.begin() + (N + 2));

	int allPay = getMaxElement(result);

	cout << allPay << "\n";

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

int getMaxValue(int a, int b) {
	int maxValue = 0;
	if (a >= b) {
		maxValue = a;
	}
	else {
		maxValue = b;
	}

	return maxValue;
}

int getMaxElement(vector<int> inputArray) {
	int maxValue = *max_element(inputArray.begin(), inputArray.end());

	return maxValue;
}