#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int i;
    vector<vector<string>>::iterator iterColumn;
    vector<string>::iterator iterRaw;

    for (iterColumn = clothes.begin(); iterColumn != clothes.end(); iterColumn++)
    {
        for (iterRaw = (*iterColumn).begin(); iterRaw != (*iterColumn).end(); iterRaw++)
        {
            cout << *iterRaw << endl;
        }
        
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