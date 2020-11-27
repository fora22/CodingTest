#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);       // testcase를 input.txt에서 입력받음
    // Clion은 working directory가 'cmake-build-debug'로 되어 있기 때문에 Edit Configurations에서 직접 절대 경로를 넣어줘야 freopen이 동작한다.
    int lenTestcase = 2;
    int N, M;
    vector<vector<int>> numberCard;
    vector<int> rowMaxNum;
    int result;

    for (int i = 0; i < lenTestcase; i++) {
        // testcase 입력
        cin >> N;
        cin >> M;
        numberCard.assign(N, vector<int>(M, 0));   // vector 크기에 맞게 형태를 초기화해줌
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> numberCard[j][k];
            }
        }

         // 연산
        for (int j = 0; j < N; j++) {
            rowMaxNum.push_back(*min_element(numberCard[j].begin(), numberCard[j].end()));  // 각 행의 최솟값을 rowMaxNum에 넣는다.
        }

        result = *max_element(rowMaxNum.begin(), rowMaxNum.end());  // 모아진 최솟값 중 최댓값이 정답
        cout << result  << endl;
    }

    return 0;
}