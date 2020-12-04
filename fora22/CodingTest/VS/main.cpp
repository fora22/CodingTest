#include <iostream>
#include <fstream>
#include <string>
/*
0���� 59 ���̿� 3�̵��� ���� ������ ����.

3, 13, 23, 30 ~ 39, 43, 53 => 15��

���� ������ ���� �����غ� �� �ִ�.

1. ���� �ð��� 3�� ���� ���
   1. �п��� 3�� ���� ��� - 15 X ���� ��� ����� �� 60 = 900
   2. �п��� 3�� ���� ��� - 45 X �ʿ��� 3�� ���� ����� �� 15 = 675
2. ���� �ð��� 3�� ���� ���
   1. ��, �� ��� ����� �� : 60 x 60 = 3600
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

		result = ((N - threecount + 1) * THREEON) + (threecount * THREEOFF);	// + 1�� 0�� �� ����� ���� �߰���
		cout << result << endl;
	}
	else
	{
		cout << "���� ���⸦ �����߽��ϴ�." << endl;
	}
	
	readFile.close();

	return 0;
}