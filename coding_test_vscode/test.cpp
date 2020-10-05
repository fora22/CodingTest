#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int lengthTestCase;
	vector<int> heightOfBuildings;
	int i;
	
	// testCase 입력
	cin >> lengthTestCase;
	for (i = 0; i < lengthTestCase; i++) {
		int heightOfBuilding;
		cin >> heightOfBuilding;
		heightOfBuildings.push_back(heightOfBuilding);
	}

	

	return 0;
}