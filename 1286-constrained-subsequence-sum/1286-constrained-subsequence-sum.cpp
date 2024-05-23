class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> subsequenceSum;

        for (int i = 0; i < nums.size(); i++) {
            nums[i] += !subsequenceSum.empty() ? subsequenceSum.front() : 0;

            while (!subsequenceSum.empty() && nums[i] > subsequenceSum.back()) {
                subsequenceSum.pop_back();
            }

            if (nums[i] > 0) {
                subsequenceSum.push_back(nums[i]);
            }

            if (i >= k && !subsequenceSum.empty() && subsequenceSum.front() == nums[i - k]) {
                subsequenceSum.pop_front();
            }
        }

        return *max_element(nums.begin(), nums.end());
    }
};