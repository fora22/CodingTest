#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "IceFrame.h"

using namespace std;

int solve(ifstream* readfile)
{
	string getInfo;
	int N, M;
	vector<vector<IceFrame*>> iceFrameMap;

	if ((*readfile).is_open())
	{
		getline(*readfile, getInfo);
		N = getInfo[0];
		M = getInfo[2];
		for (int i = 0; i < N; i++)
		{
			getline(*readfile, getInfo);
			vector<IceFrame*>* iceFrameMapRow = new vector<IceFrame*>();
			for (int j = 0; j < M; j++)
			{
				IceFrame* iceContainer = new IceFrame();
				if (getInfo[j] == 1)
				{
					// when initalize iceContainer->isHole is false. but, if number(getInfo[j] == 1) is one, that changed to true
					iceContainer->isHole = true;
				}
				iceFrameMapRow->push_back(iceContainer);
			}
			iceFrameMap.push_back(*iceFrameMapRow);
			delete iceFrameMapRow;
			
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << iceFrameMap[i][j]->isHole << endl;
		}

	}

	return 0;
}

int main(void) 
{
	ifstream readFile("input.txt");
	cout << solve(&readFile) << endl;

	return 0;
}
