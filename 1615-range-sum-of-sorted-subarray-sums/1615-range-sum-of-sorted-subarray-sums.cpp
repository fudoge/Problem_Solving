#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        vector<int> newSums;
        newSums.reserve(n * (n + 1) / 2);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                newSums.push_back(prefix[j] - prefix[i]);
            }
        }
        
        sort(newSums.begin(), newSums.end());
        
        long long ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans += newSums[i];
        }
        
        return ans % (int)(1e9 + 7);
    }
};