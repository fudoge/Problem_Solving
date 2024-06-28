class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0); // indegree[idx] = indegree value. ex1) indegree[2] = 4;
        priority_queue<int> pq;
        long long ans = 0;

        for(const auto &road : roads) {
            indegree[road[0]]++;
            indegree[road[1]]++;
        }
        
        for(int i = 0; i < n; i++) {
            pq.push(indegree[i]);
        }
        
        while(!pq.empty()) {
            ans += (long long)pq.top() * (n--);
            pq.pop();
        }

        return ans;
    }
};