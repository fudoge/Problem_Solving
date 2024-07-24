class Solution {
public:
    int getMappedNum(vector<int>& mapping, int num) {
        if(num == 0) return mapping[0];

        int res = 0;
        int digit = 1;
        while(num > 0) {
            res += digit * mapping[num % 10];
            num /= 10;
            digit *= 10;
        }

        return res;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(const auto &num : nums) {
            mp[num] = getMappedNum(mapping, num);
        }
        
        sort(nums.begin(), nums.end(), [&mp](const auto &a, const auto &b){
            return mp[a] < mp[b];
        });

        return nums;
    }
};