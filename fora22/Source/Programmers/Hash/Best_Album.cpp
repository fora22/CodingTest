#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool sortingPlays(pair<int,int> pairPlaysValue_1, pair<int, int> pairPlaysValue_2) {
    return pairPlaysValue_1.second > pairPlaysValue_2.second;
}

// bool sortingMusicAlbum()

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    map<string, vector<pair<int, int>>> musicAlbum;
    map<string, vector<pair<int, int>>>::iterator iterMusicAlbum;
    vector<pair<int, int>>::iterator iterMusicAlbumPlays;\

    vector<pair<int, int>> testResult;
    vector<pair<int, int>>::iterator iterTestResult;

    for (int i = 0; i < genres.size(); i++) {
        musicAlbum[genres[i]].push_back(make_pair(i, plays[i]));    // genres를 key로 playmap<int, intmap에 묶음
    }
    
    for (iterMusicAlbum = musicAlbum.begin(); iterMusicAlbum != musicAlbum.end(); iterMusicAlbum++) {
        sort((iterMusicAlbum->second).begin(), (iterMusicAlbum->second).end(), sortingPlays);        //  여기서 Plays를 sort 함
    }
    // --------------sort 완료

    for (iterMusicAlbum = musicAlbum.begin(); iterMusicAlbum != musicAlbum.end(); iterMusicAlbum++) {
        if (static_cast<int>(iterMusicAlbum->second.size()) == 1) {
            testResult.push_back((iterMusicAlbum->second)[0]);
        }
        else {
            testResult.push_back(iterMusicAlbum->second[0]);
            testResult.push_back(iterMusicAlbum->second[1]);
        }
    }

    for (iterTestResult = testResult.begin(); iterTestResult != testResult.end(); iterTestResult++) {
        cout << (*iterTestResult).first<< " , " << (*iterTestResult).second << endl;
    }
    // for (iterMusicAlbum = musicAlbum.begin(); iterMusicAlbum != musicAlbum.end(); iterMusicAlbum++) {
    //     for (iterMusicAlbumPlays = iterMusicAlbum->second.begin(); iterMusicAlbumPlays != iterMusicAlbum->second.end(); iterMusicAlbumPlays++) {
    //         cout << (*iterMusicAlbumPlays).first << " : " << (*iterMusicAlbumPlays).second << " , ";
    //     }
    //     cout << endl;
    // }

    return {0, 1};
}

int main(void)
{
    vector<string> genres_test_1 = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays_test_1 = { 500, 600, 150, 800, 2500 }; 

    vector<int> returnAnswer = solution(genres_test_1, plays_test_1);
    // vector<int>::iterator iterAnswer;
    // for (iterAnswer = returnAnswer.begin(); iterAnswer != returnAnswer.end(); iterAnswer++) {
    //     cout << *iterAnswer << endl;
    // }
    

    return 0;
}