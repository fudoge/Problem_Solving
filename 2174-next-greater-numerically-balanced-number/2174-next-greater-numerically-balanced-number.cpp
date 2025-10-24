#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
   public:
    static vector<int> beautiful;
    static vector<int> init() {
        vector<int> list;
        vector<int> freq(10, 0);
        Solution().generate(0, list, freq);
        sort(list.begin(), list.end());
        return list;
    }
    bool isBeautiful(vector<int>& freq) {
        for (int i = 0; i < 10; i++) {
            if (freq[i] > 0 && freq[i] != i) return false;
        }
        return true;
    }
    void generate(ll curr, vector<int>& list, vector<int>& freq) {
        if (curr > 0 && isBeautiful(freq)) {
            list.emplace_back(curr);
        }
        if (curr > 1224444) return;

        for (int i = 1; i <= 6; i++) {
            if (freq[i] < i) {
                freq[i]++;
                generate(curr * 10 + i, list, freq);
                freq[i]--;
            }
        }
    }
    int nextBeautifulNumber(int n) {
        return *upper_bound(beautiful.begin(), beautiful.end(), n);
    }
};
vector<int> Solution::beautiful = Solution::init();