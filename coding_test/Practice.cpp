#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool sortPlays(pair<int, int> pairPlaysValue_1, pair<int, int> pairPlaysValue_2) {
    if (pairPlaysValue_1.second == pairPlaysValue_2.second) {
        return pairPlaysValue_1.first < pairPlaysValue_2.first;
    }
    else {
        return pairPlaysValue_1.second > pairPlaysValue_2.second;
    }
    
}

bool sortMusicAlbum(vector<pair<int, int>> value_1, vector<pair<int, int>> value_2) {
    return value_1[0].second > value_2[0].second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    map<string, vector<pair<int, int>>> musicAlbum;
    map<string, vector<pair<int, int>>>::iterator iterMusicAlbum;
    vector<pair<int, int>>::iterator iterMusicAlbumPlays; \

    vector<vector<pair<int, int>>> testResult;
    vector<vector<pair<int, int>>>::iterator iterTestResult;

    int i;
    for (i = 0; i < genres.size(); i++) {
        musicAlbum[genres[i]].push_back(make_pair(i, plays[i]));    // genres를 key로 playmap<int, intmap에 묶음
    }

    for (iterMusicAlbum = musicAlbum.begin(); iterMusicAlbum != musicAlbum.end(); iterMusicAlbum++) {
        sort((iterMusicAlbum->second).begin(), (iterMusicAlbum->second).end(), sortPlays);        //  여기서 Plays를 sort 함
    }

    // -------------plays sort complete

    for (iterMusicAlbum = musicAlbum.begin(); iterMusicAlbum != musicAlbum.end(); iterMusicAlbum++) {
        // key에 해당하는 vector를 옮김
        testResult.push_back(iterMusicAlbum->second);
    }

    for (iterTestResult = testResult.begin(); iterTestResult != testResult.end(); iterTestResult++) {
        // key에 해당하는 vector 중 최댓값이 큰 것으로 sort
        sort(testResult.begin(), testResult.end(), sortMusicAlbum);
    }


    // --------------sort 완료
    vector<pair<int, int>>::iterator iterPair;
    vector<int> answer;
    for (iterTestResult = testResult.begin(); iterTestResult != testResult.end(); iterTestResult++) {
        if ((*iterTestResult).size() == 1) {
            answer.push_back((*(*iterTestResult).begin()).first);
        }
        else
        {
            iterPair = (*iterTestResult).begin();
            for (i = 0; i < 2; i++) {
                answer.push_back((*iterPair).first);
                iterPair++;
            }
        }
    }




    // for (iterTestResult = testResult.begin(); iterTestResult != testResult.end(); iterTestResult++) {
    //     cout << (*iterTestResult).first << " , " << (*iterTestResult).second << endl;
    // }
    // for (iterMusicAlbum = musicAlbum.begin(); iterMusicAlbum != musicAlbum.end(); iterMusicAlbum++) {
    //     for (iterMusicAlbumPlays = iterMusicAlbum->second.begin(); iterMusicAlbumPlays != iterMusicAlbum->second.end(); iterMusicAlbumPlays++) {
    //         cout << (*iterMusicAlbumPlays).first << " : " << (*iterMusicAlbumPlays).second << " , ";
    //     }
    //     cout << endl;
    // }

    return answer;
}

int main(void)
{
    vector<string> genres_test_1 = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays_test_1 = { 800, 600, 800, 26000, 2500 };

    vector<int> returnAnswer = solution(genres_test_1, plays_test_1);
    vector<int>::iterator iterAnswer;
    for (iterAnswer = returnAnswer.begin(); iterAnswer != returnAnswer.end(); iterAnswer++) {
        cout << *iterAnswer << endl;
    }


    return 0;
}