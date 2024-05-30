class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int sum = n*(n+1)/2;

        for(const auto &num : nums) {
            sum -= num;
        }

        return sum;
    }
};