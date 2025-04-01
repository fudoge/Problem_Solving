#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    int ans = 0;
    unordered_map<char, int> mp;
    unordered_map<char, int> solved;
    while ((cin >> m) && m != -1) {
        char p;
        string verdict;
        cin >> p >> verdict;

        if (verdict == "wrong") {
            mp[p]++;
        } else {
            ans += m + mp[p] * 20;
            solved[p]++;
        }
    }
    cout << solved.size() << " " << ans << "\n";

    return 0;
}