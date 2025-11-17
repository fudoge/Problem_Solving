class Solution {
   public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -k - 1;
        for (int curr = 0; curr < nums.size(); curr++) {
            if (nums[curr] == 1) {
                if (curr - last <= k) return false;
                last = curr;
            }
        }
        return true;
    }
};