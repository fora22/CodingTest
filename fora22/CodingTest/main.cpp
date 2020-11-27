#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> sliceString(const string _moveCommands) {
    string _moveCommnad;
    vector<string> _inputMoveCommands;
    stringstream ss(_moveCommands);
    while (ss >> _moveCommnad) {
        _inputMoveCommands.push_back(_moveCommnad);
    }

    return _inputMoveCommands;
}

int main() {
    ifstream readFile("input.txt");
//    freopen("input.txt", "r", stdin);       // testcase를 input.txt에서 입력받음 -> ifstream으로 바꿈
//    Clion은 working directory가 'cmake-build-debug'로 되어 있기 때문에 Edit Configurations에서 직접 절대 경로를 넣어줘야 freopen이 동작한다.
    int lenTestcase = 1;
    int N;
    string strN;
    vector<vector<int>> map;
    vector<int> mapRow;
    vector<string> moveCommands = {"R", "L", "U", "D"};
    vector<string> inputMoveCommands;   // 명령어 slice해서 보관해놓는 vector
    string moveCommand;     // 명령어 입력받는 string
    vector<string>::iterator iterCommands;  // inputMoveCommnads의 iterator

    if (readFile.is_open()) {
        for (int i = 0; i < lenTestcase; i++) {
            // testcase 입력
            //cin >> N;     // ifstream으로 바꿈
            getline(readFile, strN);
            N = stoi(strN);
            for (int j = 1; j < (N + 1); j++) {
                vector<int> *mapRow = new vector<int>;  // map 변수 행에 들어갈 vector
                for (int k = 1; k < (N + 1); k++) {
                    (*mapRow).push_back(k);
                }
                map.push_back(*mapRow);
                delete mapRow;
            }
//        명령어 입력
            getline(readFile, moveCommand);
            inputMoveCommands = sliceString(moveCommand);
            int x = 1;
            int y = 1;
            for(iterCommands = inputMoveCommands.begin(); iterCommands != inputMoveCommands.end(); iterCommands++) {
                if (((*iterCommands) == moveCommands[0]) && (y < N)) {
                    y += 1;
                } else if (((*iterCommands) == moveCommands[1]) && (y > 1)) {
                    y -= 1;
                } else if (((*iterCommands) == moveCommands[2]) && (x > 1)){
                    x -= 1;
                } else if (((*iterCommands) == moveCommands[3]) && (x < N)) {
                    x += 1;
                }
            }

            cout << x << " " << y  << endl;

        }
    } else if (readFile.fail()) {
        cout << "file can not open" << endl;
    }
    readFile.close();
    return 0;
}