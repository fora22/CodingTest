/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	int T = 10;
	int test_case;
	int lengthTestCase;			   // test_case의 길이
	vector<int> heightOfBuildings; // test_case에서 빌딩 높이를 받을 vector
	int i;

	vector<int> aroundHeight; // 해당 빌딩 주변의 높이를 기억할 vector
	int aroundMaxHeight;	  // 주변 빌딩 높이 중 가장 높은 높이를 저장할 변수
	int viewPointSum = 0;	  // result 값
	for (test_case = 1; test_case <= T; test_case++)
	{
		// testCase 입력
		cin >> lengthTestCase;
		for (i = 0; i < lengthTestCase; i++)
		{
			int heightOfBuilding;
			cin >> heightOfBuilding;
			heightOfBuildings.push_back(heightOfBuilding);
		}

		for (i = 2; i < (lengthTestCase - 2); i++)
		{
			aroundHeight = {heightOfBuildings[i - 2], heightOfBuildings[i - 1], heightOfBuildings[i + 1], heightOfBuildings[i + 2]};
			if ((heightOfBuildings[i] > aroundHeight[0]) && (heightOfBuildings[i] > aroundHeight[1]) && (heightOfBuildings[i] > aroundHeight[2]) && (heightOfBuildings[i] > aroundHeight[3]))
			{
				aroundMaxHeight = *max_element(aroundHeight.begin(), aroundHeight.end());
				viewPointSum += heightOfBuildings[i] - aroundMaxHeight;
			}
		}
		cout << "#" << test_case << " " << viewPointSum << endl;
	}

	return 0; //정상종료시 반드시 0을 리턴해야합니다.
}