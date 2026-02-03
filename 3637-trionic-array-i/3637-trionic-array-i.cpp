class Solution {
public:
    bool move(vector<int>& nums, int &i, int dir) {
        int n = nums.size();
        int j = i;
        if(dir & 1) {
            while(j+1 < n && nums[j] > nums[j+1]) {
                j++;
            }
        } else {
            while(j+1 < n && nums[j] < nums[j+1]) {
                j++;
            }
        }
        bool res = j - i > 0;
        i = j;
        return res;
    }
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        if(!move(nums, i, 0)) return false;
        if(!move(nums, i, 1)) return false;
        if(!move(nums, i, 0)) return false;

        return i == n-1;
    }
};