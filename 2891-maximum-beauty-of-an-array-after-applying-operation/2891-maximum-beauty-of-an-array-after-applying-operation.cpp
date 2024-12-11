class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;
        deque<int> dq;
        for(int i = 0; i < n; ++i) {
            while(!dq.empty() && dq.front() + 2 * k < nums[i]) dq.pop_front();
            dq.push_back(nums[i]);

            ans = max(ans, (int)dq.size());
        }
        return ans;
    }
};