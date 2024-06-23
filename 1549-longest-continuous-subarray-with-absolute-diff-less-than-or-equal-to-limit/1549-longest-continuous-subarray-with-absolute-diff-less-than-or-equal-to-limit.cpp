class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans = 0;
        int left = 0;
        deque<int> maxDQ, minDQ;

        for (int right = 0; right < n; right++) {
            while (!maxDQ.empty() && nums[maxDQ.back()] <= nums[right]) {
                maxDQ.pop_back();
            }
            maxDQ.push_back(right);

            while (!minDQ.empty() && nums[minDQ.back()] >= nums[right]) {
                minDQ.pop_back();
            }
            minDQ.push_back(right);

            while (nums[maxDQ.front()] - nums[minDQ.front()] > limit) {
                left++;
                if (maxDQ.front() < left) {
                    maxDQ.pop_front();
                }
                if (minDQ.front() < left) {
                    minDQ.pop_front();
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};