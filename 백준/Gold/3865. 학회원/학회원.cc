#include <bits/stdc++.h>

#include <ios>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while ((cin >> n) && n != 0) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, bool> visited;
        string start;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;

            int l = 0, r = 0;
            while (str[r] != ':') {
                r++;
            }
            string src = str.substr(0, r - l);
            visited[src] = false;
            if (i == 0) start = src;
            r++;
            l = r;

            while (r < str.size() && str[r] != '.') {
                while (str.size() && str[r] != '.' && str[r] != ',') {
                    r++;
                }
                string dst = str.substr(l, r - l);
                adj[src].emplace_back(dst);
                visited[dst] = false;
                r++;
                l = r;
            }
        }

        queue<string> q;
        q.emplace(start);
        visited[start] = true;

        int ans = 0;
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (adj[curr].size() == 0) ans++;
            for (const auto &next : adj[curr]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.emplace(next);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}