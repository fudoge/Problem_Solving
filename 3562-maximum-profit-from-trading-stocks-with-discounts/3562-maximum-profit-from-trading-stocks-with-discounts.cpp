class Solution {
public:
    const int INF = 1e9;
    int n, B;
    vector<int> present, future;
    vector<vector<int>> adj;
    // dp[u][parentbought][budget]
    vector<vector<vector<int>>> dp;
    void dfs(int u) {
        for(int v : adj[u]) {
            dfs(v);
        }

        for(int parentBought = 0; parentBought <= 1; parentBought++) {
            int price = parentBought? present[u] / 2 : present[u];
            int profit = future[u] - price;

            vector<int> curr(B+1, 0);

            vector<int> base(B+1, 0);
            for(int v : adj[u]) {
                vector<int> next(B+1, 0);
                for(int b1 = 0; b1 <= B; b1++) {
                    for(int b2 = 0; b1 + b2 <= B; b2++) {
                        next[b1 + b2] = max(next[b1 + b2], base[b1] + dp[v][0][b2]);
                    }
                }
                base.swap(next);
            }

            for(int b = 0; b <= B; b++) {
                curr[b] = base[b];
            }

            if(price <= B) {
                vector<int> baseBuy(B+1, 0);
                for(int v : adj[u]) {
                    vector<int> next(B+1, 0);
                    for(int b1 = 0; b1 <= B; b1++) {
                        for(int b2 = 0; b1 + b2 <= B; b2++) {
                            next[b1 + b2] = max(next[b1 + b2], baseBuy[b1] + dp[v][1][b2]);
                        }
                    }
                    baseBuy.swap(next);
                }
                
                for(int b = price; b <= B; b++) {
                    curr[b] = max(curr[b], baseBuy[b-price] + profit);
                }
            }

            dp[u][parentBought] = move(curr);
        }
    }
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        this -> n = n;
        this -> B = budget;
        this -> present = present;
        this -> future = future;
        adj.resize(n);
        for(auto &h : hierarchy) {
            adj[h[0]-1].emplace_back(h[1]-1);
        }

        dp.resize(n, vector<vector<int>>(2, vector<int>(B+1)));

        dfs(0);

        int ans = 0;
        for(int b = 0; b <= B; b++) {
            ans = max(ans, dp[0][0][b]);
        }

        return ans;
    }
};