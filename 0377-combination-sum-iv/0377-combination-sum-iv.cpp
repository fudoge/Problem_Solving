#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int countCombinations(vector<int>& nums, int remainingTarget) {
        if (remainingTarget == 0)
            return 1;

        if (remainingTarget < 0)
            return 0;

        if (dp[remainingTarget] != -1)
            return dp[remainingTarget];

        int currentCombinations = 0;

        for (int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            currentCombinations += countCombinations(nums, remainingTarget - currentNum);
        }

        dp[remainingTarget] = currentCombinations;
        return currentCombinations;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return countCombinations(nums, target);
    }
};