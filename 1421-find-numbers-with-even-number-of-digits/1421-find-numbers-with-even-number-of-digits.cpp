class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(const auto &num : nums) {
            if((int)log10(num) & 1) ans++;
        } 
        return ans;
    }
};