class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return {};

        vector<int> result(n - k + 1);
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                result[i - k + 1] = nums[dq.front()];
            }
        }

        return result;
    }
};