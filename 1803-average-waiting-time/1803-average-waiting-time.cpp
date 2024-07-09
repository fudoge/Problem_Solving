class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int currTime = customers[0][1] + customers[0][0];
        long long sum = customers[0][1];
        for(int i = 1; i < n; i++) {
            if(currTime > customers[i][0]) {
                sum += currTime - customers[i][0];
            }
            sum += customers[i][1];
            currTime = max(currTime, customers[i][0]) + customers[i][1];
        }

        return (double)sum / n;
    }
};