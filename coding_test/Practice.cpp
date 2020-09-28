#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, string> clothesDictionary;


    for (int i = 0; i < clothes.size() ; i++) {
        clothesDictionary.insert(make_pair(clothes[i][0], clothes[i][1]));
    }
    map<string, string>::iterator iterMap;
    

    for (iterMap = clothesDictionary.begin(); iterMap != clothesDictionary.end(); iterMap++) {
        cout << "key : " << iterMap->first << "  value : " << iterMap->second << endl;
    }
    int answer = 0;

    return answer;
}

int main(void)
{
    vector<vector<string>> test_1 = { {"yellow_hat", "headgear"} ,{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
    vector<vector<string>> test_2 = {{"crow_mask", "face"}, { "blue_sunglasses", "face" }, { "smoky_makeup", "face" }};
    int returnAnswer = solution(test_1);
    cout << boolalpha << returnAnswer << endl;

    //string s = "41";
    //string t = "4112";
    //
    //int test = t.find(s, 0);
    //cout << test << endl;


    return 0;
}