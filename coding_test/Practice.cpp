#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string>* participant, vector<string>* completion) {
    sort(participant->begin(), participant->end());
    sort(completion->begin(), completion->end());

    string answer;
    const int participantSize = participant->size();
    
    for (int i = 0; i < participantSize; i++)
    {
        if ((*participant)[i] != (*completion)[i]){

            answer = (*participant)[i];
            break;
        }
    }

    return answer;
}

int main(void)
{
    vector<string> p = {"c", "b", "d", "a", "a"};
    vector<string> c = { "c", "b", "d", "a"};

    vector<string>* pptr = &p;
    vector<string>* cptr = &c;
    string s;
    s = solution(pptr, cptr);
    int i = 0;
    int pSize = p.size();
    int cSize = c.size();
    for (i = 0; i < pSize; i++)
    {
        cout << p[i] << endl;
    }
    for (i = 0; i < cSize; i++)
    {
        cout << c[i] << endl;
    }
    return 0;
}