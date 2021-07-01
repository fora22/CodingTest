# 그리디 알고리즘
그리디(Greedy) 알고리즘은 탐욕 알고리즘이라고도 불리며 매 선택에서 지금 이 순간 당장 최적인 답을 선택하는 알고리즘이다. 예를 들어 목적지까지 여러 교차로를 통해 지나간다면 매 교차로마다 다음 교차로까지 가장 짧은(최적의) 경로로 이동하는 선택을 그리디 알고리즘이다.

물론 이것이 가장 최적의 답을 제시한다는 보장은 없기 때문에 그리디가 사용될려면 최적이라는 보장이 있어야 한다.
## 그리디의 해법
주어진 문제에서 최대 혹은 최소가 되는 값 먼저 적용시키면 된다. 특히 대부분의 문제는 데이터를 정렬시키는 것이 필요하다. 

# 11_4 만들 수 없는 금액
## 처음 생각했을 때
주어진 화폐단위(3 2 1 1 9)를 정렬(1 1 2 3 9)하고 for문으로 순차적으로 돌면서 만들 수 없는 금액인지 판단하려 했다.

예를 들어 
1.  화폐 단위의 첫 1로 1원은 만들 수 있음
2.  화폐 단위의 2번째까지 1 1이므로, 1 + 1 = 2를 만들 수 있음
3.  화폐 단위의 3번째까지 2이므로 1 + 1 + 2 = 4, 3도 만들 수 있고 4도 만들 수 있음
4.  계속 반복 하다가 만들 수 없으면 그것이 최솟값

허나 문제는 만약 주어진 화폐가(1 4 5 9)이면 3을 만들 수 없지만 1 + 4 = 5이므로 만들 수 있다고 판단되는 예외가 발생 -> 잘못된 문제풀이

___ 
결국 도저히 모르겠어서 인터넷 검색 후 방법을 알게되었다.

인터넷에서는 `target`이라고 정해서 다음 화폐가 `target`보다 크면 최솟값인지 판단할 수 있다고 설명했다. 이해가 안되서 내 방식으로 정리를 해보았다.

`target`의 초기값은 1이다. 그리고 그 다음 정렬된 화폐들이 하나씩 순차적으로 `target`에 더해지는데 이떄 `target`은 다음과 같다.

`target` = 1 + [순차적으로 더해진 화폐 종류]

### (1 1 2 3 9)의 경우
1. target = 1이므로 1원으로 만들 수 있다.
2. target은 1 + (1) = 2가 된다.
3. target = 2인데 다음 화폐는 1원이므로 1 + **1** = 2 때문에 만들 수 있다.
4. target은 1 + (1 + 1) = 3가 된다.
5. target = 3인데 다음 화폐는 2이다. 2는 3보다 작으므로 이미 이전 과정을 통해 만들 수 있는 것을 알 수 있다(만들 수 없으면 5번 과정으로 넘어올 수 없음).
6. target은 1 + (1 + 1 + 2) = 5가 된다.
7. target은 1 + 4 = 5이므로 4원까지는 기존 것으로 만들 수 있다. 다음 화폐는 3이므로 이 또한 만들 수 있다.
8. target은 1 + (1 + 1 + 2 + 3) = 8이 된다.
9. target은 1 + 7 = 8이므로 7원까지는 기존 것으로 만들 수 있다. 다음 화페가 8원이라면 그 자체로 만들 수 있으나, 9원이기 때문에 기존 화폐 + 지금 들어오는 화폐로는 만들 수 없다. 즉 8이 만들 수 없는 최솟값이다.
## 풀이 코드
### Python
```python
import os, sys
dirName = os.getcwd()
sys.stdin = open(dirName + "\\input.txt", 'r')

N = int(input())
coins = list(map(int,input().split()))
target = 1
coins.sort()
for c in coins:
    if target < c:
        break
    target += c

print(target)
```
### C++
```cpp
#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sliceArrayComposedInt(string sLine);
bool compare(int a, int b);

int main(void) {
	ifstream readFile("input.txt");
	string getData;
	int N;
	vector<int> coins;

	if (readFile.is_open()) {
		getline(readFile, getData);
		N = getData[0] - '0';

		getline(readFile, getData);
		
		coins = sliceArrayComposedInt(getData);
	}

	int target = 1;
	sort(coins.begin(), coins.end(), compare);
	
	for (int i = 0; i < coins.size(); i++) {
		if (target < coins[i]){
			break;
		}
		target += coins[i];
	}

	cout << target << endl;

	return 0;
}

bool compare(int a, int b) {
	return a < b;
}

vector<int> sliceArrayComposedInt(string sLine) {
	int previous = 0;
	int current = 0;
	vector<int> resultSliceString;

	current = sLine.find(" ");
	while (current != string::npos) {
		string substring = sLine.substr(previous, current - previous);
		resultSliceString.push_back(stoi(substring));
		previous = current + 1;
		current = sLine.find(" ", previous);
	}
	resultSliceString.push_back(stoi(sLine.substr(previous, current - previous)));
	// slice end

	return resultSliceString;
}
```
# 11_5 볼링공 고르기
## 처음 생각했을 때
보자마자 확률문제에서 나오는 조합(Combination) 문제가 생각났다. 즉 N개의 볼링공 중에 2개를 뽑아 조합하는 경우의 수가 전체 경우의 수이다. (nC2)

그런데 주어진 조건에 서로 무게가 다른 볼링공을 골라야 하므로 for문 2개에 무게가 같은 것을 걸러주는 if문 하나로 문제를 쉽게 풀 수 있다.

## 아쉬운 점
for문을 2개 쓰기 때문에 복잡도가 O(N^2)이 나올 것이다. 메모리나 시간 제한이 빠듯한 문제이면 이 해결법은 사용하지 못한다.

## 풀이 코드
### Python
```python
import os, sys
dirName = os.getcwd()
sys.stdin = open(dirName + "\\input.txt", 'r')
N, M = map(int, input().split())
weights = list(map(int, input().split()))


ballCount = 0
for i in range(len(weights) - 1):
    for j in range(i, len(weights)):
        if weights[i] != weights[j]:
            ballCount += 1

print(ballCount)

```
### C++
```cpp
#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sliceArrayComposedInt(string sLine);

int main(void) {
	ifstream readFile("input.txt");
	string getData;
	int N, M;
	vector<int> weights;

	if (readFile.is_open()) {
		getline(readFile, getData);
		vector<int> nm;
		nm = sliceArrayComposedInt(getData);
		N = nm[0];
		M = nm[1];

		getline(readFile, getData);
		weights = sliceArrayComposedInt(getData);
	}

	int ballCount = 0;
	
	for (int i = 0; i < (weights.size() - 1); i++) {
		for (int j = i; j < weights.size(); j++) {
			if (weights[i] != weights[j]) {
				ballCount += 1;
			}
		}
	}

	cout << ballCount << endl;

	return 0;
}

vector<int> sliceArrayComposedInt(string sLine) {
	int previous = 0;
	int current = 0;
	vector<int> resultSliceString;

	current = sLine.find(" ");
	while (current != string::npos) {
		string substring = sLine.substr(previous, current - previous);
		resultSliceString.push_back(stoi(substring));
		previous = current + 1;
		current = sLine.find(" ", previous);
	}
	resultSliceString.push_back(stoi(sLine.substr(previous, current - previous)));
	// slice end

	return resultSliceString;
}
```
