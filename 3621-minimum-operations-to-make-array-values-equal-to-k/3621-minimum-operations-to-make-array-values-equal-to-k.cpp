class Solution {
   public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (nums[0] < k) return -1;

        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums[0] > k ? nums.size() : nums.size() - 1;
    }
};