#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n), baselen(n), exps(n), more_exps(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (arr[i] % 2 == 0) {
            arr[i] >>= 1;
            exps[i]++;
        }
        baselen[i] = 63 - __builtin_clz(arr[i]) + 1;
    }

    for (int i = 1; i < n; i++) {
        ll prevbaselen = baselen[i - 1];
        ll prevbase = arr[i - 1];
        ll prevexp = exps[i - 1] + more_exps[i - 1];

        ll curbaselen = baselen[i];
        ll curbase = arr[i];
        ll curexp = exps[i];

        if (prevbaselen < curbaselen) {
            ll lendiff = curbaselen - prevbaselen;
            prevbase <<= lendiff;
            prevexp -= lendiff;
        } else if (curbaselen < prevbaselen) {
            ll lendiff = prevbaselen - curbaselen;
            curbase <<= lendiff;
            curexp -= lendiff;
        }

        ll expdiff = prevexp - curexp;
        if (expdiff > 0) more_exps[i] = expdiff;
        if (curexp <= prevexp && curbase < prevbase) more_exps[i]++;
    }

    cout << accumulate(more_exps.begin(), more_exps.end(), 0LL) << "\n";

    return 0;
}