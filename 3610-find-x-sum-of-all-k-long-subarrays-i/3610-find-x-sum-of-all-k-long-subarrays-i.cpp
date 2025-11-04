#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using pii = pair<int, int>;
class Solution {
   public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++) {
            vector<int> freq(51);
            for (int j = 0; j < k; j++) {
                freq[nums[i + j]]++;
            }

            vector<pii> parr;
            for (int j = 0; j < 51; j++) {
                if (freq[j] > 0) parr.emplace_back(freq[j], j);
            }

            sort(parr.begin(), parr.end(), [](const auto& a, const auto& b) {
                if (a.first == b.first) return a.second > b.second;
                return a.first > b.first;
            });

            int sum = 0;
            for (int j = 0; j < x; j++) {
                if (j >= parr.size()) break;
                sum += parr[j].first * parr[j].second;
            }

            ans.emplace_back(sum);
        }
        return ans;
    }
};