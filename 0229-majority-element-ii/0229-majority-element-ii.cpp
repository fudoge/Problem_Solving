class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        const int n = nums.size();
        const int minimum = n / 3;
        unordered_map<int, int> um;

        for (const auto& num : nums) {
            um[num]++;
        }

        vector<int> result;
        for(const auto& num : um) {
            if(num.second > minimum) {
                result.push_back(num.first);
            }
        }
        return result;
    }
};