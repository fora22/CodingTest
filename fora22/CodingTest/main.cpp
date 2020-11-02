#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int makeBigNumber(vector<int> numbers, int M, int K) {
    int firstValue, secondValue;
    firstValue = numbers[0];
    secondValue = numbers[1];

    int quotient = M / (K + 1);       // REVIEW - 몫
    int remainder = M % (K + 1);      // REVIEW - 나머지

    int result = (((firstValue * K) + secondValue) * quotient) + (firstValue * remainder);

    return result;
}

int main() {
    // REVIEW - NMK[0]은 N, NMK[1]은 M, NMK[2]는 K
    vector<int> NMK = {5, 7, 2};        // REVIEW - N, M, K
    vector<int> N_Number = {3,4,3,4,3};     // REVIEW - N개의 자연수
    vector<int>::iterator iterNumber;
    sort(N_Number.begin(), N_Number.end(), greater<int>());

    int result = makeBigNumber(N_Number, NMK[1], NMK[2]);
    cout << result  << endl;

    return 0;
}