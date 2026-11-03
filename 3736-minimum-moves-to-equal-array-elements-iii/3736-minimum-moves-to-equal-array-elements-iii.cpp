class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());

        int ans = 0;
        for(int num : nums) {
            ans += maxNum - num;
        }

        return ans;
    }
};