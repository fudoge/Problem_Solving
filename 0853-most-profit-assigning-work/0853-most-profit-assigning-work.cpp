class Solution {
public:
    int getMax(int ability, vector<vector<int>>& works) {
        int res = 0;
        for(int i = 0; i < works.size() && ability >= works[i][0]; i++) {
            res = max(res, works[i][1]);
        }
        return res;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        int ans = 0;
        vector<vector<int>> works;
        for(int i = 0; i < n; i++) {
            works.push_back({difficulty[i], profit[i]});
        }

        sort(works.begin(), works.end());
        for(int i = 0; i < m; i++) {
            ans += getMax(worker[i], works);
        }

        return ans;
    }
};