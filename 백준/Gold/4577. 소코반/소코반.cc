#include <bits/stdc++.h>

using namespace std;

bool check(vector<string>& mat) {
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            if(mat[i][j] == 'b' || mat[i][j] == '+') return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    int round = 1;
    while(true) {
        cin >> r >> c;
        if(r == 0 && c == 0) break;

        pair<int, int> player = {0, 0};
        vector<string> mat(r);
        for(int i = 0; i < r; i++) {
            cin >> mat[i];
            for(int j = 0; j < c; j++) {
                if(mat[i][j] == 'w' || mat[i][j] == 'W') {
                    player = {i, j};
                }
            }
        }
        string command;
        cin >> command;

        char before = mat[player.first][player.second] == 'W' ? '+' : '.';
        bool completed = false;

        for(const auto &cmd : command) {
            int dx = 0, dy = 0;
            switch (cmd) {
                case 'L': {
                    dx = 0;
                    dy = -1;
                    break;
                }
                case 'R': {
                    dx = 0;
                    dy = 1;
                    break;
                }
                case 'U': {
                    dx = -1;
                    dy = 0;
                    break;
                }
                case 'D': {
                    dx = 1;
                    dy = 0;
                    break;
                }
            }

            pair<int, int> next = {player.first + dx, player.second + dy};
            char nextPlace = mat[next.first][next.second];
            if(nextPlace == '#') continue;

            if(nextPlace == '.') {
                mat[player.first][player.second] = before;
                before = mat[next.first][next.second];
                player = next;
                mat[player.first][player.second] = 'w';
            } else if(nextPlace == '+') {
                mat[player.first][player.second] = before;
                before = mat[next.first][next.second];
                player = next;
                mat[player.first][player.second] = 'W';
            } else if(nextPlace == 'b') {
                pair<int, int> blockNext = {next.first + dx, next.second + dy};
                if(mat[blockNext.first][blockNext.second] == '.') {
                    mat[blockNext.first][blockNext.second] = 'b';
                    mat[player.first][player.second] = before;
                    before = '.';
                    player = next;
                    mat[player.first][player.second] = 'w';
                } else if(mat[blockNext.first][blockNext.second] == '+') {
                    mat[blockNext.first][blockNext.second] = 'B';
                    mat[player.first][player.second] = before;
                    before = '.';
                    player = next;
                    mat[player.first][player.second] = 'w';
                }
            } else if(nextPlace == 'B') {
                pair<int, int> blockNext = {next.first + dx, next.second + dy};
                if(mat[blockNext.first][blockNext.second] == '.') {
                    mat[blockNext.first][blockNext.second] = 'b';
                    mat[player.first][player.second] = before;
                    before = '+';
                    player = next;
                    mat[player.first][player.second] = 'W';
                } else if(mat[blockNext.first][blockNext.second] == '+') {
                    mat[blockNext.first][blockNext.second] = 'B';
                    mat[player.first][player.second] = before;
                    before = '+';
                    player = next;
                    mat[player.first][player.second] = 'W';
                }
            }

            completed = check(mat);

            // for(int i = 0; i < r; i++) {
            //     cout << mat[i] << "\n";
            // }
            // cout << "\n";
            if(completed) break;
        }

        if(completed) {
            cout << "Game " << round << ": " << "complete\n";
        } else {
            cout << "Game " << round << ": " << "incomplete\n";
        }

        for(int i = 0; i < r; i++) {
            cout << mat[i] << "\n";
        }

        round++;
    }

    return 0;
}
