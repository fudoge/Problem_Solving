class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<pair<double, int>> table;
        for(int i = 0; i < n; i++) {
            table.push_back({(double)(wage[i]) / quality[i], i});
        }

        sort(table.begin(), table.end());
        priority_queue<int> pq;
        int qualitySum = 0;
        double maxRate = 0;
        for(int i = 0; i < k; i++) {
            qualitySum += quality[table[i].second];
            maxRate = max(maxRate, table[i].first);
            pq.push(quality[table[i].second]);
        }

        double ans = maxRate * qualitySum;
        for(int i = k; i < n; i++) {
            maxRate = max(maxRate, table[i].first);
            qualitySum -= pq.top(); 
            pq.pop();

            qualitySum += quality[table[i].second];
            pq.push(quality[table[i].second]);
            ans = min(ans, maxRate * qualitySum);
        }

        return ans;
    }
};