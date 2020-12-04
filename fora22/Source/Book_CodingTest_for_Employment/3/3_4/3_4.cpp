#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);       // testcase를 input.txt에서 입력받음
    // Clion은 working directory가 'cmake-build-debug'로 되어 있기 때문에 Edit Configurations에서 직접 절대 경로를 넣어줘야 freopen이 동작한다.
    int lenTestcase = 2;
    int N, K;
    int result;

    for (int i = 0; i < lenTestcase; i++) {
        // testcase 입력
        cin >> N;
        cin >> K;

        // 연산
        while (N != 1) {
            if ((N % K) == 0) {
                N = N / K;
                result += 1;
            } else {
                N -= 1;
                result += 1;
            }
        }

        cout << "최소 횟수는 " << result << endl;
    }

    return 0;
}