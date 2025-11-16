const int MOD = 1e9 + 7;
class Solution {
   public:
    int numSub(string s) {
        int n = s.size();
        long long ans = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (s[right] == '0') {
                left = right + 1;
            } else {
                ans = (ans + (right - left + 1)) % MOD;
            }
        }
        return ans % MOD;
    }
};