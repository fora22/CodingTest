#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int solve(string position);
bool problemInit(vector<pair<int, int>> *movePtr, map<string, int> *mapColumnPtr);
int checkNumberOfCases(pair<int, int>* move__, int x, int y);

int main(void) {
	
	//solve("a1");

	return 0;
}

int solve(string position) {
	vector<pair<int, int>> move;
	map<string,int> mapColumn;
	vector<pair<int, int>>::iterator iterMove;
	int numberOfCases = 0;	// result

	if (!problemInit(&move, &mapColumn)) {
		return -1;		// Initalize
	}
	
	for (iterMove = move.begin(); iterMove != move.end(); iterMove++) {
		numberOfCases += checkNumberOfCases(&(*iterMove), mapColumn[position.substr(0, 1)], stoi(position.substr(1, 2)));
	}
	
	cout << numberOfCases << endl;

	return numberOfCases;
}

int checkNumberOfCases(pair<int, int> *move__, int x, int y) {
	x += move__->first;
	y += move__->second;

	if ((x > 8) || (y > 8) || (x < 1) || (y < 1)) {
		return 0;
	}
	else {
		return 1;
	}
}

bool problemInit(vector<pair<int, int>> *movePtr, map<string, int> *mapColumnPtr) {
	try
	{
		// first number of pair is x_axis, second number of pair is y_axis.
		(*movePtr).push_back(make_pair(2, 1));	// go right and turn left
		(*movePtr).push_back(make_pair(2, -1));	// go right and turn right
		(*movePtr).push_back(make_pair(-2, 1));	// go left and turn right
		(*movePtr).push_back(make_pair(-2, -1));	// go left and turn left
		(*movePtr).push_back(make_pair(1, 2));	// go up and turn right
		(*movePtr).push_back(make_pair(1, -2));	// go up and turn left
		(*movePtr).push_back(make_pair(-1, 2));	// go down and turn left
		(*movePtr).push_back(make_pair(-1, -2));	// go down and turn right

		(*mapColumnPtr).insert(make_pair("a", 1));
		(*mapColumnPtr).insert(make_pair("b", 2));
		(*mapColumnPtr).insert(make_pair("c", 3));
		(*mapColumnPtr).insert(make_pair("d", 4));
		(*mapColumnPtr).insert(make_pair("e", 5));
		(*mapColumnPtr).insert(make_pair("f", 6));
		(*mapColumnPtr).insert(make_pair("g", 7));
		(*mapColumnPtr).insert(make_pair("h", 8));

		return true;
	}
	catch (const std::exception&)
	{
		cout << "Init failed" << endl;
		return false;
	}
}