class Solution {
public:
    int count(vector<int>& nums, int x) {
        auto it = lower_bound(nums.begin(), nums.end(), x);
        return distance(it, nums.end());
    }

    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= n; i++) {
            if(count(nums, i) == i) return i;
        }
        return -1;
    }
};
