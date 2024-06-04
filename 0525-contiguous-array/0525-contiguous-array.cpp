class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                sum--;
            } else {
                sum++;
            }

            if(sum == 0) {
                maxLen = i+1;
                continue;
            }

            if(!mp[sum]) {
                mp[sum] = i+1;
            } else {
                maxLen = max(maxLen, i - mp[sum]+1);
            }
        }

        return maxLen;
    }
};