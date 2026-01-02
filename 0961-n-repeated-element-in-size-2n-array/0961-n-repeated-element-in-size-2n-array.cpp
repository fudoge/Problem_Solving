class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n2 = nums.size();
        vector<int> freq(10001, 0);

        for(int num : nums) {
            if(++freq[num] == n2/2) {
                return num;
            }
        }

        return -1;
    }
};