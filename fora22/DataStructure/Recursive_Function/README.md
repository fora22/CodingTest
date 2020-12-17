# 재귀함수 : Recursive Function
어떤 사건이 자기 자신을 포함하고 다시 자기 자신을 사용하여 정의될 때 재귀적(recursive)이라고 한다.

재귀함수는 하나의 함수에서 자신을 다시 호출하여 작업을 수행하는 방식으로 주어진 문제를 푸는 방법이다.

재귀함수를 지속적으로 반복되면 보통 콜스택 초과(Stack Overflow)로 프로그램이 뻗어버린다.

# 예제
## 팩토리얼 : Factorial
```cpp
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
```
## 피보나치 수열 : Fibonacci Sequence
```cpp
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
```

# Reference
[재귀함수](https://namu.wiki/w/%EC%9E%AC%EA%B7%80%ED%95%A8%EC%88%98)