#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> getMap(int n, int m, ifstream* readfile)
{
	string info;
	vector<vector<int>> result; // result is dungeon

	if ((*readfile).is_open())
	{
		for (int i = 0; i < n; i++)
		{
			getline(*readfile, info);
			vector<int>* mapRow = new vector<int>();
			for (int j = 0; j < m; j++)
			{
				mapRow->push_back(info[j] - '0');
			}
			result.push_back(*mapRow);
			delete mapRow;
		}
	}

	return result;
}

int solve(ifstream *readFile) 
{
	int N, M;
	string getInfo;

	if ((*readFile).is_open())
	{
		getline(*readFile, getInfo);
		// getInfo[0] is char("4"). It is  ASCII code. ASCII code start at 48. So when you want char to int, you duplicate 48 or '0'. '0' is 48 in ASCII code
		N = getInfo[0] - '0';
		M = getInfo[2] - '0';
	}
	vector<vector<int>> dungeon = getMap(N, M, readFile);

	vector<pair<int, int>> direction = { 
		make_pair(0, 1),	// up
		make_pair(0, -1),	// down
		make_pair(-1,0),	// left
		make_pair(1, 0)		// right
	};

	// Show Map
	cout << "Showing Map" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << dungeon[i][j];
		}
		cout << endl;
	}
	cout << "Map End" << endl << endl;

	// calculate
	queue<pair<int, int>> findRoad;
	findRoad.push(make_pair(0, 0));
	int px, py, npx, npy;			// position x, position y, next position x, next position y
	while (!findRoad.empty())
	{
		px = findRoad.front().first;
		py = findRoad.front().second;
		findRoad.pop();

		for (int i = 0; i < 4; i++)
		{
			npx = px + direction[i].first;
			npy = py + direction[i].second;
			if ((npx < 0) || (npy < 0) || (npx > (N - 1)) || (npy > (M - 1)))
			{
				continue;
			}
			else if (dungeon[npx][npy] == 0)
			{
				continue;
			}
			else if (dungeon[npx][npy] == 1)
			{
				dungeon[npx][npy] = dungeon[px][py] + 1;
				findRoad.push(make_pair(npx, npy));
			}
		}
	}
	return dungeon[N - 1][M - 1];
}



int main(void) {
	
	ifstream readfile("input.txt");
	cout << solve(&readfile) << endl;

	return 0;
}