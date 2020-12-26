#include <iostream>
#include <random>
#include <vector>

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
		//randomArray[i] = i + 1;
		randomArray[i] = dis(gen); // CountSort use when data is type:int and range of data can express.
									// So, I push random & overlap data to randomArray.
	}

	//for (int i = 0; i < randomNumberCount; i++)
	//{
	//	x = dis(gen);
	//	y = dis(gen);
	//	if (x != y)
	//	{
	//		temp = randomArray[x];
	//		randomArray[x] = randomArray[y];
	//		randomArray[y] = temp;
	//	}
	//}

	return randomArray;
}

vector<int> countSort(vector<int>* rArray) {
	int arraySize = (*rArray).size();
	vector<int> countArray(arraySize);

	int temp;
	for (int i = 0; i < arraySize; i++) {
		temp = (*rArray)[i];
		countArray[temp] = countArray[temp] + 1;
	}

	return countArray;
}


int main(void) 
{
	const int randNumberLength = 100;
	vector<int> randArray = getRandomArray(randNumberLength);

	vector<int> resultArray = countSort(&randArray);

	for (int i = 0; i < resultArray.size(); i++) {
		for (int j = 0; j < resultArray[i]; j++) {
			cout << i << endl;
		}
	}

	return 0;
}
