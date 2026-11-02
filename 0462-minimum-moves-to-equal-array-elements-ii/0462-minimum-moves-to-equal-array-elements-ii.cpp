class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mid = n/2;
        int med = nums[mid];

        int ans = 0;
        for(int num : nums) {
            ans += abs(num - med);
        }

        return ans;
    }
};
