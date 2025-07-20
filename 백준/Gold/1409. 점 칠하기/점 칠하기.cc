#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    vector<int> ang(n), idx(360, -1);
    for (int i = 0; i < n; i++) {
        cin >> ang[i];
        idx[ang[i]] = i;
    }

    int ans = 0;
    vector<int> stk;
    for (int rot = 1; rot < 360; ++rot) {
        vector<bool> vis(n, 0);
        int cur = 0;
        for (int s = 0; s < n; ++s) {
            if (vis[s]) continue;
            int sz = 0;
            stk.clear();
            stk.emplace_back(s);
            vis[s] = 1;

            while (!stk.empty()) {
                int u = stk.back();
                stk.pop_back();
                ++sz;

                int vAng = (ang[u] + rot) % 360;
                int v = idx[vAng];
                if (v != -1 && !vis[v]) {
                    vis[v] = 1;
                    stk.emplace_back(v);
                }

                vAng = (ang[u] - rot + 360) % 360;
                v = idx[vAng];
                if (v != -1 && !vis[v]) {
                    vis[v] = 1;
                    stk.emplace_back(v);
                }
            }
            cur += sz / 2;
        }
        ans = max(ans, cur * 2);
    }

    cout << ans << "\n";

    return 0;
}
