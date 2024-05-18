class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for(auto n : nums){
            ones = (~twos) & (ones ^ n);
            twos = (~ones) & (twos ^ n);
        }
        return ones;
    }
};