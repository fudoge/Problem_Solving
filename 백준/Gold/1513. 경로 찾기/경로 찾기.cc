#include <bits/stdc++.h>

using namespace std;

const int MOD = 1'000'007;

int n, m, c;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> c;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<vector<vector<int>>>> dp(
        n, vector<vector<vector<int>>>(
               m, vector<vector<int>>(
                      51, vector<int>(51))));  // r, c, count, maxNum;

    for (int i = 1; i <= c; i++) {
        int r, c;
        cin >> r >> c;
        mat[r - 1][c - 1] = i;
    }

    if (mat[0][0] != 0)
        dp[0][0][1][mat[0][0]] = 1;
    else
        dp[0][0][0][0] = 1;

    for (int i = 1; i < n; i++) {
        if (mat[i][0] > 0) {
            int gameNo = mat[i][0];
            for (int k = 1; k <= c; k++) {
                for (int l = 0; l < gameNo; l++) {
                    dp[i][0][k][gameNo] =
                        (dp[i][0][k][gameNo] + dp[i - 1][0][k - 1][l]) % MOD;
                }
            }
        } else {
            for (int k = 0; k <= c; k++) {
                for (int l = 0; l <= 50; l++) {
                    dp[i][0][k][l] =
                        (dp[i][0][k][l] + dp[i - 1][0][k][l]) % MOD;
                }
            }
        }
    }
    for (int j = 1; j < m; j++) {
        if (mat[0][j] > 0) {
            int gameNo = mat[0][j];
            for (int k = 1; k <= c; k++) {
                for (int l = 0; l < gameNo; l++) {
                    dp[0][j][k][gameNo] =
                        (dp[0][j][k][gameNo] + dp[0][j - 1][k - 1][l]) % MOD;
                }
            }
        } else {
            for (int k = 0; k <= c; k++) {
                for (int l = 0; l <= 50; l++) {
                    dp[0][j][k][l] =
                        (dp[0][j][k][l] + dp[0][j - 1][k][l]) % MOD;
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] > 0) {
                int gameNo = mat[i][j];
                for (int k = 1; k <= c; k++) {
                    for (int l = 0; l < gameNo; l++) {
                        dp[i][j][k][gameNo] =
                            (dp[i][j][k][gameNo] + dp[i - 1][j][k - 1][l]) %
                            MOD;
                        dp[i][j][k][gameNo] =
                            (dp[i][j][k][gameNo] + dp[i][j - 1][k - 1][l]) %
                            MOD;
                    }
                }
            } else {
                for (int k = 0; k <= c; k++) {
                    for (int l = 0; l <= 50; l++) {
                        dp[i][j][k][l] =
                            (dp[i][j][k][l] + dp[i - 1][j][k][l]) % MOD;
                        dp[i][j][k][l] =
                            (dp[i][j][k][l] + dp[i][j - 1][k][l]) % MOD;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= c; i++) {
        int ans = 0;
        for (int j = 0; j <= 50; j++) {
            ans = (ans + dp[n - 1][m - 1][i][j]) % MOD;
        }
        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}
