#include <bits/stdc++.h>

#include <numeric>

using namespace std;

int LIMIT = 1 << 20;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n), baselen(n), exps(n), more_exps(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (arr[i] % 2 == 0) {
            arr[i] >>= 1;
            exps[i]++;
        }
        baselen[i] = ceil(log2(arr[i] + 1));
    }

    for (int i = 1; i < n; i++) {
        int prevbaselen = baselen[i - 1];
        int prevbase = arr[i - 1];
        int prevexp = exps[i - 1] + more_exps[i - 1];

        int curbaselen = baselen[i];
        int curbase = arr[i];
        int curexp = exps[i];

        if (prevbaselen < curbaselen) {
            int lendiff = curbaselen - prevbaselen;
            prevbase <<= lendiff;
            prevexp -= lendiff;
        } else if (curbaselen < prevbaselen) {
            int lendiff = prevbaselen - curbaselen;
            curbase <<= lendiff;
            curexp -= lendiff;
        }

        int expdiff = prevexp - curexp;
        if (expdiff > 0) more_exps[i] = expdiff;
        if (curexp <= prevexp && curbase < prevbase) more_exps[i]++;
    }

    cout << accumulate(more_exps.begin(), more_exps.end(), 0) << "\n";

    return 0;
}