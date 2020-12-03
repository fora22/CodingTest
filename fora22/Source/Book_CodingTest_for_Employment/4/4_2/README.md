# 4_2 시각 문제
[설명 링크](https://freedeveloper.tistory.com/272?category=888096)

3이 하나라도 포함되는 모든 경우의 수를 구하는 문제인데, 바로 3 6 9 게임이 떠올랐다.

 시:분:초 이고 시각이 N으로 입력받기 때문에 분과 초의 경우의 수 곱하기 N의 경우의 수를 해주면 구할 수 있다.

 ## 3을 세기
 0에서 59 사이에 3이들어가는 수는 다음과 같다.

3, 13, 23, 30 ~ 39, 43, 53 => 15개

따라서 다음과 같이 생각해볼 수 있다.

1. 만약 시간에 3이 없을 경우
   1. 분에서 3이 있을 경우 - 15 X 초의 모든 경우의 수 60 = 900
   2. 분에서 3이 없을 경우 - 45 X 초에서 3이 있을 경우의 수 15 = 675
2. 만약 시간에 3이 있을 경우
   1. 분, 초 모든 경우의 수 : 60 x 60 = 3600

만약 입력이 N = 5 라면 5시 59분 59초 까지 모든 경우의 수를 출력해야 하므로

- 0시, 1시, 2시, 4시, 5시 -> (900 + 675) X 5 = 7875
- 3시 -> 3600 X 1 = 3600

총 11475의 경우의 수가 나온다.
## 구현
시간은 범위가 0~23이므로 나올 수 있는(3이 있는) 경우의 수가 다음과 같다.
- 3
- 13
- 23 
  

따라서 if문 으로 구현하려 한다.
```cpp
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
	cout << result << endl;
	}
	else
	{
		cout << "파일 열기를 실패했습니다." << endl;
	}
	
	readFile.close();

	return 0;
}
```
