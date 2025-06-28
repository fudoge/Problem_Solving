#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll h;
    cin >> h;
    ll q, r;
    cin >> q >> r;

    vector<ll> ends = {0};
    for (ll level = 1; level <= h; ++level) {
        ends.emplace_back(ends.back() + level);
    }

    vector<double> arr(h + 3);
    for (int i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;

        int level = lower_bound(ends.begin(), ends.end(), a) - ends.begin();
        int startIdx = a - ends[level - 1];
        if (startIdx == 0) startIdx = level + 1;
        int len = h - level + 2;

        arr[startIdx] += (double)b / (double)len;
        arr[startIdx + len] -= (double)b / (double)len;
    }

    vector<double> parr(h + 3);
    parr[0] = 0.0;
    double curr = 0;
    for (int i = 1; i <= h + 2; i++) {
        curr += arr[i];
        parr[i] = parr[i - 1] + curr;
    }

    for (int i = 0; i < r; i++) {
        int a, b;
        cin >> a >> b;
        cout << fixed << setprecision(4) << parr[b] - parr[a - 1] << "\n";
    }

    return 0;
}
