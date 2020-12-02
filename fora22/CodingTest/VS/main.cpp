#include <iostream>
#include <fstream>
#include <string>
/*
0에서 59 사이에 3이들어가는 수는 다음과 같다.

3, 13, 23, 30 ~ 39, 43, 53 => 15개

따라서 다음과 같이 생각해볼 수 있다.

1. 만약 시간에 3이 없을 경우
   1. 분에서 3이 있을 경우 - 15 X 초의 모든 경우의 수 60 = 900
   2. 분에서 3이 없을 경우 - 45 X 초에서 3이 있을 경우의 수 15 = 675
2. 만약 시간에 3이 있을 경우
   1. 분, 초 모든 경우의 수 : 60 x 60 = 3600
*/
#define THREEON 1575		// 15 x 60 = 900, 45 x 15 = 675 -> 900 + 675 = 1575
#define THREEOFF 3600		// 60 x 60 = 3600

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
		cout << result << endl;
	}
	else
	{
		cout << "파일 열기를 실패했습니다." << endl;
	}
	
	readFile.close();

	return 0;
}