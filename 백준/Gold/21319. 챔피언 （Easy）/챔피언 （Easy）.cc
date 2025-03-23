#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n;

bool check(int i, vector<int> &a) {
    ll grown = a[i];
    int lb = lower_bound(a.begin(), a.end(), grown) - a.begin();

    if (lb < i) {
        return false;
    }
    grown += lb;

    int nextIdx = i + 1;
    while (nextIdx < n) {
        int gain = lower_bound(a.begin() + nextIdx, a.end(), grown) -
                   (a.begin() + nextIdx);
        if (gain == 0) return false;
        grown += gain;
        nextIdx += gain;
    }
    return true;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (check(i, a)) ans.emplace_back(i + 1);
    }

    if (ans.empty())
        cout << "-1\n";
    else {
        for (const auto &answer : ans) {
            cout << answer << " ";
        }
        cout << "\n";
    }
    return 0;
}