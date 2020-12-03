#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;  // REVIEW - 거스름 돈
    cin >> N;
    vector<int> coins = {500, 100, 50, 10}; // REVIEW - 나눌 코인 종류
    vector<int> countCoins;

    for (int i = 0; i < coins.size(); i++) {
        countCoins.push_back(N / coins[i]); // REVIEW - 동전 개수
        N = N % coins[i];                   // REVIEW - 남은 돈
    }

    for (int i = 0; i < countCoins.size(); i++) {
        cout << countCoins[i] << endl;
    }

    return 0;
}