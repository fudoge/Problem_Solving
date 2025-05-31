#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k;

int simulate(ll target, vector<array<int, 2>>& adj, vector<int>& instructions) {
    int p = 0;
    int idx = 0;
    for (ll t = 0; t < target; t++) {
        p = adj[p][instructions[idx]];
        idx = (idx + 1) % m;
    }
    return p;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    vector<array<int, 2>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> adj[i][0] >> adj[i][1];
        adj[i][0]--;
        adj[i][1]--;
    }

    vector<int> instructions(m);
    for (int i = 0; i < m; i++) {
        char instruction;
        cin >> instruction;
        instructions[i] = instruction == 'L' ? 0 : 1;
    }

    vector<int> visited(n * m, -1);

    int pos = 0;
    int instIdx = 0;
    ll step = 0;

    int cycleStart = -1;
    int cycleLen = -1;

    while (true) {
        int stateIdx = pos * m + instIdx;
        if (visited[stateIdx] != -1) {
            cycleStart = visited[stateIdx];
            cycleLen = step - visited[stateIdx];
            break;
        }

        visited[stateIdx] = step;
        pos = adj[pos][instructions[instIdx]];
        instIdx = (instIdx + 1) % m;
        step++;
    }

    ll t = k * m;

    int ans;
    if (t < cycleStart) {
        ans = simulate(t, adj, instructions);
    } else {
        ll rem = (t - cycleStart) % cycleLen;
        ans = simulate(cycleStart + rem, adj, instructions);
    }

    cout << ans + 1 << "\n";
    return 0;
}