static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int cnt = 0;
    
        for(const auto &num : nums) {
            mp[num]++;
        }

        for(const auto &val : mp) {
            int amount = val.second;
            if(amount == 1) return -1;
            cnt += amount/3;
            if(amount%3 > 0) cnt++;
        }

        return cnt;
    }
};