class Solution {
   public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n - 2);
        vector<int> ans;
        for (int num : nums) {
            if (freq[num] == 1) ans.emplace_back(num);
            freq[num]++;
        }

        return ans;
    }
};