#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> parr(n);
    for (int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s;

        parr[i] = {t, s};
    }

    sort(parr.begin(), parr.end(),
         [](const auto& a, const auto& b) { return a.second > b.second; });

    int currTime = INT_MAX;
    for (int i = 0; i < n; i++) {
        int t = parr[i].first;
        int s = parr[i].second;

        currTime = min(currTime, s) - t;
    }

    cout << (currTime >= 0 ? currTime : -1) << "\n";

    return 0;
}
