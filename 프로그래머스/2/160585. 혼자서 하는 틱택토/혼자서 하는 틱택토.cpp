#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isGameEnd(char ch, vector<string>& board) {
    // horizontal..
    for(int i = 0; i < 3; i++) {
        if (board[i][0] == ch && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        return true;
    }
    //vertical..
    for(int i = 0; i < 3; i++) {
        if (board[0][i] == ch && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        return true;
    }
    //cross..
    if (board[1][1] == ch && board[1][1] == board[0][0] && board[1][1] == board[2][2])
        return true;
    if (board[1][1] == ch && board[1][1] == board[2][0] && board[1][1] == board[0][2])
        return true;

    return false;
}

int solution(vector<string> board) {
    int o_times = 0;
    int x_times = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O')
                o_times++;
            else if (board[i][j] == 'X')
                x_times++;
        }
    }

    if (x_times > o_times || abs(x_times - o_times) > 1)
        return 0;

    bool endWithO = isGameEnd('O', board);
    bool endWithX = isGameEnd('X', board);

    if (endWithO && endWithX)
        return 0;

    if (endWithO && o_times == x_times || endWithX && o_times == x_times+1) {
        return 0;
    }
    
    return 1;
}
