class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int min_element = INT_MAX;
        for(int num : nums) {
            sum += num;
            min_element = min(min_element, num);
        }

        return sum - n * min_element;
    }
};