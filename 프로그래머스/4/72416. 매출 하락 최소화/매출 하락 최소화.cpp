#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> graph;
vector<int> saless;
int n;

void dfs(int root) {
    int sum_val = 0;
    int lowestGap = graph[root].size() > 0? 1e9 : 0;
    vector<int> mins;
    int not_attended = 0;

    for (const auto &child : graph[root]) {
        dfs(child);
        mins.push_back(min(dp[child][0], dp[child][1]));

        if (dp[child][0] < dp[child][1]) {
            not_attended++;
        }
        if(dp[child][1] > dp[child][0]) {
            lowestGap = min(lowestGap, dp[child][1] - dp[child][0]);
        }
    }

    for (const auto &m : mins) {
        sum_val += m;
    }

    // 팀장이 참석한 경우
    dp[root][1] = saless[root] + sum_val;

    // 팀장이 참석하지 않은 경우
    if (not_attended < graph[root].size()) {
        // 1. 팀원 중에 참가자가 있음
        dp[root][0] = sum_val;
    } else {
        // 2. 팀원 중에 참가자가 없음. 부하 직원들 중에서 가장 매출이 적은 직원을 참가.
        dp[root][0] = sum_val + lowestGap;
    }
    
    // cout << "root: " << root << " " << "attended: 1, sale: " << dp[root][1] << endl;
    // cout << "root: " << root << " " << "attended: 0, sale: " << dp[root][0] << endl;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    n = sales.size();
    dp.resize(n + 1, vector<int>(2, 0));
    graph.resize(n + 1);
    saless = vector<int>(n + 1, 0);

    for (int i = 0; i < n; i++) {
        saless[i + 1] = sales[i];
    }

    for (const auto &link : links) {
        int a = link[0];
        int b = link[1];
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        // 자식 노드가 없으면
        if (graph[i].empty()) {
            dp[i][1] = saless[i];
            dp[i][0] = 0;
        }
    }

    dfs(1);

    return min(dp[1][0], dp[1][1]);
}
