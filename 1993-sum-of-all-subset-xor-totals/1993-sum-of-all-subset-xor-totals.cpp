class Solution {
   public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for(const auto & num : nums) {
            ans |= num;
        }

        return ans * (1 << (nums.size()-1));
    }
};