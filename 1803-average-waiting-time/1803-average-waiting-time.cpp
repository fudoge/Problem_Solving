#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int currTime = customers[0][1] + customers[0][0];
        long long sum = customers[0][1];
        for(int i = 1; i < n; i++) {
            sum += customers[i][1] + (currTime > customers[i][0]? currTime - customers[i][0] : 0);
            currTime = max(currTime, customers[i][0]) + customers[i][1];
        }

        return (double)sum / n;
    }
};