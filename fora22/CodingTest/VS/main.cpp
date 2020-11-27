#include <iostream>
#include <fstream>
#include <string>;
#define THREEON 1575
#define THREEOFF 3600

using namespace std;

int main(void) {
	ifstream readFile("input.txt");
	string strN;
	int N;
	int result = 0;
	int threecount = 0;

	if (readFile.is_open())
	{
	getline(readFile, strN);
	N = stoi(strN);

	if (N >= 23)
	{
		threecount = 3;
	}
	else if (N >= 13)
	{
		threecount = 2;
	}
	else if (N >= 3)
	{
		threecount = 1;
	}
	else
	{
		threecount = 0;
	}

	result = ((N - threecount + 1) * THREEON) + (threecount * THREEOFF);	// + 1은 0일 때 경우의 수를 추가함
	cout << "ㅁㅁ" << result << endl;
	}
	else
	{
		cout << "파일 열기를 실패했습니다." << endl;
	}
	
	readFile.close();

	return 0;
}