class Solution {
public:
    int minPairSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;
        int maxPairSum = -1;

        while(left < right) {
            maxPairSum = max(maxPairSum, nums[left] + nums[right]);
            left++;
            right--;
        }

        return maxPairSum;
    }
};