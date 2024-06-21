class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int n = customers.size();
        int maxProfit = 0;
        for(int i = 0; i < minutes; i++) {
            if(!grumpy[i]) {
                ans += customers[i];
            } else {
                maxProfit += customers[i];
            }
        }
        int newProfit = maxProfit;
        for(int i = minutes; i < n; i++) {
            if(!grumpy[i]) {
                ans += customers[i];
            } else {
                newProfit += customers[i];
            }
            if(grumpy[i - minutes]) {
                newProfit -= customers[i-minutes];
            }
            maxProfit = max(maxProfit, newProfit);
        }

        return ans + maxProfit;
    }
};