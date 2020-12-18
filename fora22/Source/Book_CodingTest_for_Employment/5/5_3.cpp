#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include "IceFrame.h"

using namespace std;

vector<vector<IceFrame*>> getData(int _N, int _M, ifstream* readFile)
{
	string getInfo;
	int N, M;
	vector<vector<IceFrame*>> _iceFrameMap;

	if ((*readFile).is_open())
	{
		for (int i = 0; i < _N; i++)
		{
			getline(*readFile, getInfo);
			vector<IceFrame*>* iceFrameMapRow = new vector<IceFrame*>();
			for (int j = 0; j < _M; j++)
			{
				IceFrame* iceContainer = new IceFrame();
				if ((getInfo[j] - '0') == 1)
				{
					// when initalize iceContainer->isHole is false. but, if number(getInfo[j] == 1) is one, that changed to true
					iceContainer->visited = true;
				}
				iceFrameMapRow->push_back(iceContainer);
			}
			_iceFrameMap.push_back(*iceFrameMapRow);
			delete iceFrameMapRow;
		}
	}

	return _iceFrameMap;
}

bool searchIce(int px, int py, vector<vector<IceFrame*>> *map)
{
	// Position X, Position Y
	int mapN = (*map).size();
	int mapM = (*map)[0].size();

	if ((px <= -1) || (px >= mapN) || (py <= -1) || (py >= mapM))
	{
		return false;
	}
	if (!(*map)[px][py]->visited)
	{
		(*map)[px][py]->visited = true;
		
		searchIce(px - 1, py, map);
		searchIce(px + 1, py, map);
		searchIce(px, py + 1, map);
		searchIce(px, py - 1, map);
		return true;
	}

	return false;
}

int solve(ifstream* readfile)
{
	int N, M;
	string getInfo;
	int result = 0;

	if ((*readfile).is_open())
	{
		getline(*readfile, getInfo);
		N = getInfo[0] - '0';		// getInfo[0] is char("4"). It is  ASCII code. ASCII code start at 48. So when you want char to int, you duplicate 48 or '0'
		M = getInfo[2] - '0';		// '0' is 48 in ASCII code
	}
	vector<vector<IceFrame*>> iceFrameMap = getData(N, M, readfile);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (searchIce(i, j, &iceFrameMap))
			{
				result++;
			}
		}
	}
	
	return result;
}

int main(void) 
{
	ifstream readFile("input.txt");
	cout << solve(&readFile) << endl;
	return 0;
}
