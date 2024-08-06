#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(const auto &letter : word) {
            freq[letter - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        int pushCount = 1;

        for(int i = 0; i < 8; i++) {
            ans += freq[i] * pushCount;
        }
        pushCount++;
        for(int i = 8; i < 16; i++) {
            ans += freq[i] * pushCount;
        }
        pushCount++;
        for(int i = 16; i < 24; i++) {
            ans += freq[i] * pushCount;
        }
        pushCount++;
        for(int i = 24; i < 26; i++) {
            ans += freq[i] * pushCount;
        }

        return ans;
    }
};