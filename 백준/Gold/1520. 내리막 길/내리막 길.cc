#include <bits/stdc++.h>

using namespace std;

int n, m;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (x == n - 1 && y == m - 1) return 1;

    if (dp[x][y] != -1) return dp[x][y];

    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[x][y] > mat[nx][ny]) {
            res += dfs(nx, ny, mat, dp);
        }
    }

    return dp[x][y] = res;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m)), dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << dfs(0, 0, mat, dp) << "\n";

    return 0;
}