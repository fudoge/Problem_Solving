class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(true) {
            int n = nums.size();
            int minpidx = -1;
            int minp = INT_MAX;
            bool sorted = true;
            for(int i = 0; i < n-1; i++) {
                if(nums[i] > nums[i+1]) {
                    sorted = false;
                }
                int sum = nums[i] + nums[i+1];
                if(sum < minp) {
                    minp = sum;
                    minpidx = i;
                }
            }
            if(sorted) break; 
            
            nums[minpidx] += nums[minpidx+1];
            nums.erase(nums.begin() + minpidx + 1);
            ans++;
        }
        return ans;
    }
};