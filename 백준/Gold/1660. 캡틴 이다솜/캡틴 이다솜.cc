#include <bits/stdc++.h>

using namespace std;

int solve(int left, vector<int>& a, vector<int>& dp) {
    if (left == 0) return 0;
    if (dp[left] != -1) {
        return dp[left];
    }

    int res = INT_MAX;
    for (int i = 0; i < a.size(); i++) {
        if (left - a[i] >= 0) {
            res = min(res, solve(left - a[i], a, dp) + 1);
        }
    }

    return dp[left] = res;
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;

    vector<int> a;
    vector<int> dp(n + 1, -1);
    int k = 1;
    int j = 2;
    for (int i = 1; i <= 300000; i += k) {
        a.emplace_back(i);
        k += j;
        j++;
    }

    cout << solve(n, a, dp) << "\n";

    return 0;
}