class Solution {
   public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for (const auto& num : nums) s.insert(num);

        int n = nums.size();
        int left = 0;
        int completeCount = s.size();
        int elems = 0;
        int ans = 0;
        unordered_map<int, int> freq;
        for (int right = 0; right < n; right++) {
            freq[nums[right]]++;
            if (freq[nums[right]] == 1) elems++;

            while (left <= right && elems == completeCount) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) elems--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};