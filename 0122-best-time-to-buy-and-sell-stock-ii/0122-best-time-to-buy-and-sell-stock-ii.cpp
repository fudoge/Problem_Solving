class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int profit = 0;

        for(int i = 0; i < n-1; i++){
            const auto curr = prices[i];
            const auto next = prices[i+1];
            if(next-curr > 0){
                profit += next-curr;
            }
        }

        return profit;
    }
};