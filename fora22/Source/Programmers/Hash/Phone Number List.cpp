#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int answerInt;
    const int phoneBookSize = phone_book.size() - 1;
    int i;

    pair<vector<string>::iterator, vector<string>::iterator> min = minmax_element(phone_book.begin(), phone_book.end());
    const int phoneBookEraseIndex = find(phone_book.begin(), phone_book.end(), *min.first) - phone_book.begin();
    vector<string>::iterator phoneBookEraseIterator = phone_book.begin() + phoneBookEraseIndex;
    string findNumber = *(min.first);
    phone_book.erase(phoneBookEraseIterator);


    for (i = 0; i < phoneBookSize; i++)
    {
        answerInt = phone_book[i].find(findNumber, 0);
        if (answerInt == -1) {
            continue;
        }
        else {
            answer = false;
        }
    }

    return answer;
}

int main(void)
{
    vector<string> test_1 = { "119", "97674223", "1195524421" };
    vector<string> test_2 = { "123", "456", "789" };
    vector<string> test_3 = { "12", "123", "1235", "567", "88" };
    vector<string>* testPtr = &test_1;
    bool returnAnswer = solution(test_2);
    cout << boolalpha << returnAnswer << endl;

    //string s = "41";
    //string t = "4112";
    //
    //int test = t.find(s, 0);
    //cout << test << endl;


    return 0;
}