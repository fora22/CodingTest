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

int exchangeValue(vector<int>* exchangeArray, int xIndex, int yIndex) {
	int temp = (*exchangeArray)[xIndex];
	(*exchangeArray)[xIndex] = (*exchangeArray)[yIndex];
	(*exchangeArray)[yIndex] = temp;
	
	return 0;
}

int quickSort(vector<int>* rArray, int first, int last) {
	if (first >= last) {
		return 0;
	}
	int pivot = (*rArray)[first];
	int pivotIndex = first;
	int leftPartionIndex = first + 1;
	int rightPartionIndex = last;
	
	while (leftPartionIndex <= rightPartionIndex) {
		while ((leftPartionIndex <= last) && ((*rArray)[leftPartionIndex] <= pivot)) {
			leftPartionIndex++;
		}
		while ((rightPartionIndex > first) && ((*rArray)[rightPartionIndex] >= pivot)) {
			rightPartionIndex--;
		}

		if (leftPartionIndex <= rightPartionIndex) {
			exchangeValue(rArray, leftPartionIndex, rightPartionIndex);
		} else {
			exchangeValue(rArray, rightPartionIndex, pivotIndex);
		}
	}
	quickSort(rArray, first, rightPartionIndex - 1);
	quickSort(rArray, rightPartionIndex + 1, last);

	return 0;
}


int main(void) 
{
	const int randNumberLength = 100;
	vector<int> randArray = getRandomArray(randNumberLength);

	quickSort(&randArray, 0, randNumberLength - 1);

	for (int i = 0; i < randArray.size(); i++) {
		cout << randArray[i] << endl;
	}

	return 0;
}
