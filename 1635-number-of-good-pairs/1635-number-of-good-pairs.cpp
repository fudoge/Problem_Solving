class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> um;
        int pairs = 0;

        for(const auto& num : nums) {
            pairs += um[num];
            um[num]++;
        }

        return pairs;
    }
};