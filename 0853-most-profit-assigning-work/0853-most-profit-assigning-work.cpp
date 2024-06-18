#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int getMax(int ability, vector<vector<int>>& works) {
        int left = 0, right = works.size() - 1;
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (works[mid][0] <= ability) {
                res = (res, works[mid][1]);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return res;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        int ans = 0;
        vector<vector<int>> works;
        
        for (int i = 0; i < n; i++) {
            works.push_back({difficulty[i], profit[i]});
        }

        sort(works.begin(), works.end());

        for (int i = 1; i < works.size(); i++) {
            works[i][1] = max(works[i][1], works[i-1][1]);
        }

        for (int i = 0; i < m; i++) {
            ans += getMax(worker[i], works);
        }

        return ans;
    }
};