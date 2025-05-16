#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dp[x] = dp[x - 1] + 1;
        maxLen = max(maxLen, dp[x]);
    }
    cout << n - maxLen << "\n";
    return 0;
}
