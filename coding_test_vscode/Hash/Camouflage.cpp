#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {

    map<string, vector<string>> clothesDictionary;  // key value로 묶을 map STL
    vector<int> keySize;                            // value의 개수를 담을 vector
    vector<vector<string>>::iterator iterClothes;
    map<string, vector<string>>::iterator iterClothesDictionary;


    for (iterClothes = clothes.begin(); iterClothes != clothes.end(); iterClothes++) {
        clothesDictionary[(*iterClothes)[1]].push_back((*iterClothes)[0]);     // 종류는 key로 옷 내용은 value로 넣음
    }

    int answer = 1;
    int i = 0;

    for (iterClothesDictionary = clothesDictionary.begin(); iterClothesDictionary != clothesDictionary.end(); iterClothesDictionary++) {

        keySize.push_back(iterClothesDictionary->second.size() + 1);        // 종류의 수 + 1(아무것도 선택안함)를 넣는다.
        answer *= keySize[i];
        i++;
    }
    // 모든 것을 아무것도 선택하지 않을 경우의 수를 뺌
    return answer - 1;
}

int main(void)
{
    vector<vector<string>> test_1 = { {"yellow_hat", "headgear"} ,{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
    vector<vector<string>> test_2 = { {"crow_mask", "face"}, { "blue_sunglasses", "face" }, { "smoky_makeup", "face" } };
    int returnAnswer = solution(test_1);
    cout << boolalpha << returnAnswer << endl;

    return 0;
}