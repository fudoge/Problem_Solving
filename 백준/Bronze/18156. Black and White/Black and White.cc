#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    bool flag = true;

    for (int i = 0; i < n; i++) {
        int rW = 0;
        int rB = 0;
        int streak = 1;
        char last = '-';
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'W')
                rW++;
            else
                rB++;
            if (last == mat[i][j])
                streak++;
            else
                streak = 1;
            if (streak >= 3) {
                flag = false;
            }
            last = mat[i][j];
        }
        if (rW != rB) flag = false;
    }

    for (int j = 0; j < n; j++) {
        int rW = 0;
        int rB = 0;
        int streak = 1;
        char last = '-';
        for (int i = 0; i < n; i++) {
            if (mat[i][j] == 'W')
                rW++;
            else
                rB++;
            if (last == mat[i][j])
                streak++;
            else
                streak = 1;
            if (streak >= 3) {
                flag = false;
            }
            last = mat[i][j];
        }
        if (rW != rB) flag = false;
    }

    if (flag)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}