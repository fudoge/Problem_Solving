#pragma GCC optimize("O3", "unroll-loops");
static const int init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int ans = 0;

        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        vector<bool> visited(n, false);
        queue<int> q;
        for(const auto &ib : initialBoxes) {
            hasBox[ib] = true;
            if(status[ib]) {
                q.emplace(ib);
                visited[ib] = true;
            }
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            ans += candies[curr];
            for(const auto &k : keys[curr]) {
                hasKey[k] = true;
                if(hasBox[k] && !visited[k] && !status[k]) {
                    q.emplace(k);
                    visited[k] = true;
                }
            }
            for(const auto &cb : containedBoxes[curr]) {
                hasBox[cb] = true;
                if((status[cb] || hasKey[cb]) && !visited[cb]) {
                    q.emplace(cb);
                    visited[cb] = true;
                }
            }
        }
        
        return ans;
    }
};