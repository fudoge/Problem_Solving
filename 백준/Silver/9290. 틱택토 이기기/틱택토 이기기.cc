#include <bits/stdc++.h>

using namespace std;

void print(int c, vector<string> &mat) {
    cout << "Case " << c << ":\n";
    for (auto &m : mat) cout << m << "\n";
}

bool check(vector<string> &mat, char ch) {
    for (int i = 0; i < 3; i++) {
        if (mat[i][0] == ch && mat[i][1] == ch && mat[i][2] == ch) return true;
        if (mat[0][i] == ch && mat[1][i] == ch && mat[2][i] == ch) return true;
    }
    if (mat[0][0] == ch && mat[1][1] == ch && mat[2][2] == ch) return true;
    if (mat[2][0] == ch && mat[1][1] == ch && mat[0][2] == ch) return true;
    return false;
}

void solve(int c, vector<string> &mat, char ch) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == '-') {
                mat[i][j] = ch;
                if (check(mat, ch)) {
                    print(c, mat);
                    return;
                }
                mat[i][j] = '-';
            }
        }
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<string> mat(3);
        cin >> mat[0] >> mat[1] >> mat[2];

        char turn;
        cin >> turn;

        solve(i, mat, turn);
    }

    return 0;
}
