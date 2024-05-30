class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> arr(n);
        int nextPositive = 0;
        int nextNegative = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                arr[nextPositive] = nums[i];
                nextPositive +=2;
            } else {
                arr[nextNegative] = nums[i];
                nextNegative += 2;
            }
        }

        return arr;
    }
};