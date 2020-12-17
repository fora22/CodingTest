#include <iostream>

using namespace std;

int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n > 1) {
		return n * factorial(n - 1);
	}
	else {
		cout << "잘못된 입력입니다." << endl;
		return -1;
	}
}

int fibonacci(int n) {
	if ((n == 0)||(n == 1)) {
		return n;
	}
	else if (n > 2) {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
	else {
		cout << "잘못된 입력입니다." << endl;
		return -1;
	}
}

int main(void) {
	int factoNumber, fiboNumber = 0;
	cout << "몇 팩토리얼을 구하고 싶으신가요 : ";
	cin >> factoNumber;
	cout << factorial(factoNumber) << endl;
	
	cout << "몇 번째 피보나치 수열을 구하고 싶으신가요 : ";
	cin >> fiboNumber;
	cout << fibonacci(fiboNumber) << endl;

	return 0;
}
