class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> s;
        for(const auto& num : nums) {
            s[num]++;
            if(s[num] >= 2) return true;
        }

        return false;
    }
};