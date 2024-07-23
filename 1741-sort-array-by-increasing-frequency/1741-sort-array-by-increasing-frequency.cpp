#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        sort(nums.begin(), nums.end(), [&freq](const auto &a, const auto &b){
            if(freq[a] == freq[b]) return a > b;
            return freq[a] < freq[b];
        });

        return nums;
    }
};