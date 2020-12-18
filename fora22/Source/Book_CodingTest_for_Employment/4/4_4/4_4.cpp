#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> initInformation(string str) {
	int previous = 0;
	int current = 0;
	vector<int> information;

	current = str.find(" ");
	while (current != string::npos)
	{
		string substring = str.substr(previous, current - previous);
		information.push_back(stoi(substring));
		previous = current + 1;
		current = str.find(" ", previous);
	}
	information.push_back(stoi(str.substr(previous, current - previous)));

	return information;
}

vector<int>::iterator turnLeft(vector<int>::iterator cD) {
	if (*cD == 3) {
		cD--;
		cD--;
		cD--;
	}
	else {
		cD++;
	}

	return cD;
}

bool confirmMoveableToAll(vector<int> cP, vector<pair<int, int>> m, vector<vector<int>> gM) {
	int x, y;
 	bool checkMoveable = true;
	for (int i = 0; i < 4; i++) {
		x = cP[0] + m[i].first;
		y = cP[1] + m[i].second;
		checkMoveable = checkMoveable && (gM[x][y] >= 1);
	}

	return checkMoveable;	// If true character should have to go 4 direction or it is sea.
}

int solve(ifstream *readFile) {
	string getInformation;
	vector<int> mapSize;
	vector<int> characterPosition;
	vector<vector<int>> gameMap;
	vector<int> mapDirection = {0, 1, 2, 3}; // North, East, South, West
	vector<int>::iterator currentDirection;	// Get Current character Direction
	int xMap, yMap;

	// Each Index means North, East, South, West. In other words if character move anywhere, you add Value(pair) to your character postion.
	vector<pair<int, int>> move = { make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1) };

	// Get Information Init
	if ((*readFile).is_open()) {
		getline(*readFile, getInformation);
		mapSize = initInformation(getInformation);
		getline(*readFile, getInformation);
		characterPosition = initInformation(getInformation);
		for (int i = 0; i < mapSize[0]; i++) {
			getline(*readFile, getInformation);
			gameMap.push_back(initInformation(getInformation));
		}
	}
	
	currentDirection = find(mapDirection.begin(), mapDirection.end(), characterPosition[2]);	

	// Start
	int count = 0;
	int debug = 0;
	while (true) {
		debug++;
		if (confirmMoveableToAll(characterPosition, move, gameMap)) {
			currentDirection = turnLeft(currentDirection);
			currentDirection = turnLeft(currentDirection);	// If twice turn Left, it is like turn back.

			xMap = characterPosition[0] + move[*currentDirection].first;
			yMap = characterPosition[1] + move[*currentDirection].second;
		
			if (gameMap[xMap][yMap] == 1) {
				break;
			}
			else if (gameMap[xMap][yMap] > 1) {
				gameMap[xMap][yMap] += 2;
			}
			else {
				gameMap[xMap][yMap] += 2;
				count++;
			}

			characterPosition[0] = xMap;
			characterPosition[1] = yMap;

			currentDirection = turnLeft(currentDirection);
			currentDirection = turnLeft(currentDirection);	// Turn back for original Direction.
		}
		else {
			currentDirection = turnLeft(currentDirection); // Turn Left

			xMap = characterPosition[0] + move[*currentDirection].first;
			yMap = characterPosition[1] + move[*currentDirection].second;

			if (gameMap[xMap][yMap] == 0) {
				gameMap[xMap][yMap] += 2;
				count++;
			}

			characterPosition[0] = xMap;
			characterPosition[1] = yMap;
		}

	}

	return count;
}



int main(void) {
	
	ifstream readfile("input.txt");
	cout << solve(&readfile) << endl;

	return 0;
}