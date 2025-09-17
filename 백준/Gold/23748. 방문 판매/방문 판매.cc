#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
int N, X, Y;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> X >> Y;
    vector<pii> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int minCount = INF;
    int lastCustomer = -1;
    for (int i = 0; i < N; i++) {
        int targetX = max(0, X - a[i].first);
        int targetY = max(0, Y - a[i].second);

        vector<vector<int>> dp(X + 1, vector<int>(Y + 1, INF));
        dp[0][0] = 0;

        for (int j = 0; j < i; j++) {
            int xi = a[j].first;
            int yi = a[j].second;
            for (int x = X; x >= 0; x--) {
                for (int y = Y; y >= 0; y--) {
                    if (dp[x][y] == INF) continue;
                    int nx = min(X, x + xi);
                    int ny = min(Y, y + yi);
                    dp[nx][ny] = min(dp[nx][ny], dp[x][y] + 1);
                }
            }
        }

        int best = INF;
        for (int x = targetX; x <= X; x++) {
            for (int y = targetY; y <= Y; y++) {
                best = min(best, dp[x][y]);
            }
        }
        if (best != INF) {
            int tot = best + 1;
            if (tot < minCount) {
                minCount = tot;
                lastCustomer = i + 1;
            }
        }
    }

    if (minCount == INF) {
        cout << "-1\n";
    } else {
        cout << minCount << "\n" << lastCustomer << "\n";
    }

    return 0;
}
