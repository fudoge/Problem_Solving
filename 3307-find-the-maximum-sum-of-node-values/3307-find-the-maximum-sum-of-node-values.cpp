class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int cnt = 0;
        long long totalSum = 0;
        int positive_Min = INT_MAX;
        int negative_Max = INT_MIN;

        for(int nodeValue : nums) {
            int nodeAfterOp = nodeValue ^ k;
            totalSum += nodeValue;
            int netChange = nodeAfterOp - nodeValue;

            if(netChange > 0) {
                positive_Min = min(netChange, positive_Min);
                totalSum += netChange;
                cnt += 1;
            } else {
                negative_Max = max(negative_Max, netChange);
            }
        }

        if(cnt % 2 == 0) {
            return totalSum;
        }

        return max(totalSum - positive_Min, totalSum + negative_Max);
    }
};