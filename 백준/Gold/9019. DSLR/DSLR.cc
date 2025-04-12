#include <bits/stdc++.h>

using namespace std;

const int MOD = 10000;
char ops[] = {'D', 'S', 'L', 'R'};

void solve() {
    int a, b;
    cin >> a >> b;
    vector<int> dist(10000, 1e9);
    vector<int> prev(10000, 1e9);
    vector<char> rollback(10000, '-');
    dist[a] = 0;
    prev[a] = -1;

    queue<int> q;
    q.emplace(a);
    while (!q.empty() && dist[b] == 1e9) {
        int curr;
        curr = q.front();
        q.pop();

        int d = curr * 2 % MOD;
        int s = (curr - 1 + MOD) % MOD;
        int l = [&]() {
            int digit234 = curr % 1000;
            int digit1 = curr / 1000;
            return digit234 * 10 + digit1;
        }();
        int r = [&]() {
            int digit4 = curr % 10;
            int digit123 = curr / 10;
            return digit4 * 1000 + digit123;
        }();
        vector<int> nexts = {d, s, l, r};
        for (int i = 0; i < 4; i++) {
            int next = nexts[i];
            char op = ops[i];
            if (dist[next] > dist[curr] + 1) {
                prev[next] = curr;
                dist[next] = dist[curr] + 1;
                rollback[next] = op;
                q.emplace(next);
            }
        }
    }
    string ans;
    int x = b;
    while (prev[x] != -1) {
        ans += rollback[x];
        x = prev[x];
    }
    reverse(ans.begin(), ans.end());

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