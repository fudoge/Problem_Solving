#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<string> mat(N);
    vector<vector<vector<vector<ll>>>> dp(
        N, vector<vector<vector<ll>>>(
               N, vector<vector<ll>>(K + 1, vector<ll>(2, 0))));
    for (int i = 0; i < N; i++) {
        cin >> mat[i];
    }
    if (N == 1) {
        cout << "1\n";
        return;
    }

    if (mat[0][1] == '.') dp[0][1][K][0] = 1;
    if (mat[1][0] == '.') dp[1][0][K][1] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] != '.') continue;
            for (int k = 0; k <= K; k++) {
                int r = dp[i][j][k][0];
                if (j + 1 < N && mat[i][j + 1] == '.') {
                    dp[i][j + 1][k][0] += r;
                }
                if (k > 0 && i + 1 < N && mat[i + 1][j] == '.') {
                    dp[i + 1][j][k - 1][1] += r;
                }
                int d = dp[i][j][k][1];
                if (i + 1 < N && mat[i + 1][j] == '.') {
                    dp[i + 1][j][k][1] += d;
                }
                if (k > 0 && j + 1 < N && mat[i][j + 1] == '.') {
                    dp[i][j + 1][k - 1][0] += d;
                }
            }
        }
    }
    ll ans = 0;
    for (int k = K; k >= 0; k--) {
        ans += dp[N - 1][N - 1][k][0];
        ans += dp[N - 1][N - 1][k][1];
    }
    cout << ans << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}