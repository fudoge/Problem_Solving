#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
private:
    int n,m;
    string key;
    unordered_map<int, vector<int>> mp; // charNo. -> idxes;
    vector<vector<int>> dp;
public:
    int solve(int idx, int pos) {
        if(idx >= m) {
            return 0;
        }
        if(dp[idx][pos] != -1) return dp[idx][pos];

        auto next = mp[key[idx] - 'a'];
        int res = 1e9;
        for(int i = 0; i < next.size(); i++) {
            int diff = abs(next[i] - pos);
            int curr_step = min(diff, n - diff);
            int next_step = solve(idx+1, next[i]);
            res = min(res, curr_step + next_step);
        }
        
        dp[idx][pos] = res + 1;
        return dp[idx][pos];
    }

    int findRotateSteps(string ring, string key) {
        n = ring.size();
        m = key.size();
        this -> key = key;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            mp[ring[i] - 'a'].push_back(i);
        }

        int ans = solve(0, 0);
        return ans;
    }
};
