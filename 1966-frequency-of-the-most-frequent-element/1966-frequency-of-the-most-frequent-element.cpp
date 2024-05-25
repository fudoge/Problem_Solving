class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        const int n = nums.size();

        sort(nums.begin(), nums.end());
        long sum = 0;
        int maxFreq = 0;

        for(int left = 0, right = 0; right < n; right++) {
            sum += nums[right];
            while(sum + k < (long)nums[right] *(right - left + 1)) {
                sum -= nums[left];
                left++;

            }
            maxFreq = max(maxFreq, right - left +1);
        }

        return maxFreq;
    }
};
