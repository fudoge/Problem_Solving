#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<pii> blocks(m);
    for (auto &i : blocks) {
        cin >> i.first;
        cin >> i.second;
    }
    sort(blocks.begin(), blocks.end());
    blocks.erase(unique(blocks.begin(), blocks.end()), blocks.end());
    int base = m - blocks.size();

    int ans = INT_MAX;
    for (int r = 1; r <= m; r++) {
        int c = m / r;
        if (r * c != m) continue;

        for (int top = 1, bottom = r; bottom <= n;) {
            for (int left = 1, right = c; right <= n;) {
                int cnt = 0;
                for (const auto &block : blocks) {
                    if (block.first < top || block.first > bottom ||
                        block.second < left || block.second > right)
                        cnt++;
                }
                ans = min(ans, cnt);

                left++;
                right++;
            }
            top++;
            bottom++;
        }
    }

    cout << ans + base << "\n";

    return 0;
}