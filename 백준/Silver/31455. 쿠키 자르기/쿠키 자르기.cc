#include <bits/stdc++.h>

using namespace std;

int dfs(int rOffset, int cOffset, int len, bool eat, vector<vector<int>> &mat) {
    int sum = 0;
    for (int i = rOffset; i < rOffset + len; i++) {
        for (int j = cOffset; j < cOffset + len; j++) {
            sum += mat[i][j];
        }
    }
    if (eat) {
        return sum;
    }

    if (len == 1) return 0;
    int selected = sum % 4;

    int res = 0;
    vector<int> newROff = {0, 0, len / 2, len / 2};
    vector<int> newCOff = {0, len / 2, 0, len / 2};
    for (int i = 0; i < 4; i++) {
        if (i == selected) {
            res += dfs(rOffset + newROff[i], cOffset + newCOff[i], len / 2,
                       true, mat);
        } else {
            res += dfs(rOffset + newROff[i], cOffset + newCOff[i], len / 2,
                       false, mat);
        }
    }

    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++) {
            mat[i][j] = temp[j] - '0';
            sum += mat[i][j];
        }
    }

    int res = dfs(0, 0, n, false, mat);
    int ans = sum - res;

    cout << ans << "\n";
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
