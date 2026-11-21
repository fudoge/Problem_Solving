#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int find_y(char ch, int y, vector<vector<int>>& dp, vector<int> &parent, string &s) {
        if(dp[y][ch-'a'] != -2) return dp[y][ch-'a'];
        if(ch == s[y]) {
            dp[y][ch-'a'] = y;
            return dp[y][ch-'a'];
        }
        if(parent[y] == -1) {
            dp[y][ch-'a'] = -1;
            return dp[y][ch-'a'];
        }
        dp[y][ch-'a'] = find_y(ch, parent[y], dp, parent, s);
        return dp[y][ch-'a'];
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        // 0 ~ n: cached parent
        // -1: not found
        // -2: unknown
        vector<vector<int>> dp(n, vector<int>(26, -2));

        vector<int> new_parent(n, -1);
        for(int i = 1; i < n; i++) {
            int y = find_y(s[i], parent[i], dp, parent, s);
            if(y != -1) {
                new_parent[i] = y; 
            }
        }
        for(int i = 1; i < n; i++) {
            if(new_parent[i] != -1) parent[i] = new_parent[i];
        }

        vector<int> ind(n);
        for(int i = 1; i < n; i++) {
            ind[parent[i]]++;
        }

        queue<int> q;
        vector<int> ans(n, 1);
        for(int i = 1; i < n; i++) {
            if(ind[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            int p = parent[curr];
            if(p != -1) {
                ind[p]--;
                ans[p] += ans[curr];
                if(ind[p] == 0) {
                    q.push(p);
                }
            }
        }

        return ans;
    }
};