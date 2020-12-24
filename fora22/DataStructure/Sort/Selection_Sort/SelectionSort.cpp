#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getRandomArray(const int randomNumberCount)
{
	int temp, x, y;
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dis(0, randomNumberCount - 1);

	vector<int> randomArray(randomNumberCount);
	
	for (int i = 0; i < randomNumberCount; i++)
	{
		randomArray[i] = i + 1;
	}

	for (int i = 0; i < randomNumberCount; i++)
	{
		x = dis(gen);
		y = dis(gen);
		if (x != y)
		{
			temp = randomArray[x];
			randomArray[x] = randomArray[y];
			randomArray[y] = temp;
		}
	}

	return randomArray;
}


int main(void) 
{
	const int randNumberLength = 100;
	vector<int> randArray = getRandomArray(randNumberLength);

	vector<int>::iterator min = min_element(randArray.begin(), randArray.end());    // random array

	int minIndex;
	int temp = 0;
	for (int i = 0; i < randArray.size(); i++)
	{
		minIndex = i;
		for (int j = i + 1; j < randArray.size(); j++)
		{
			if (randArray[minIndex] > randArray[j])
			{
				minIndex = j;
			}
		}
		temp = randArray[i];
		randArray[i] = randArray[minIndex];
		randArray[minIndex] = temp;
	}

	
	for (int i = 0; i < randArray.size(); i++)
	{
		cout << randArray[i] << endl;
	}


	return 0;
}
