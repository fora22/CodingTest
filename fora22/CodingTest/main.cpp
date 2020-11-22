#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<string> sliceString(const string _moveCommands) {
    char moveTok[250];  // 조건에서 이동횟수가 1 <= 이고, 100 >= 이므로(1이상 100 이하) 200 ~ 250칸이면 적절하다.
    char* _moveCommandPtr;
    strcpy(moveTok, _moveCommands.c_str());
    vector<string> _inputMoveCommands;
    _moveCommandPtr = strtok(moveTok, " ");
    while (_moveCommandPtr != NULL) {
        _moveCommandPtr = strtok(moveTok, " ");
        string moveCommandStr(_moveCommandPtr);      // char to string
        _inputMoveCommands.push_back((moveCommandStr));      // vector에 저장
    }

return _inputMoveCommands;
}

int main() {
    freopen("input.txt", "r", stdin);       // testcase를 input.txt에서 입력받음
//    Clion은 working directory가 'cmake-build-debug'로 되어 있기 때문에 Edit Configurations에서 직접 절대 경로를 넣어줘야 freopen이 동작한다.
    int lenTestcase = 1;
    int N;
    vector<vector<int>> map;
    vector<int> mapRow;
    vector<string> moveCommands = {"R", "L", "U", "D"};
    vector<string> inputMoveCommands;   // 명령어 slice해서 보관해놓는 vector
    int inputMoveCommandsLength = 6;
    string moveCommand;     // 명령어 입력받는 string
    vector<string>::iterator iterCommands;  // inputMoveCommnads의 iterator

    for (int i = 0; i < lenTestcase; i++) {
        // testcase 입력
        cin >> N;
        for (int j = 1; j < (N + 1); j++) {
            vector<int> *mapRow = new vector<int>;  // map 변수 행에 들어갈 vector
            for (int k = 1; k < (N + 1); k++) {
                (*mapRow).push_back(k);
            }
            map.push_back(*mapRow);
            delete mapRow;
        }
//        명령어 입력
        for (int j = 0; j < inputMoveCommandsLength; j++) {
            cin >> moveCommand;
            inputMoveCommands.push_back(moveCommand);
        }
//        getline(cin, moveCommand);
//        inputMoveCommands = sliceString(moveCommand);
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

    return 0;
}