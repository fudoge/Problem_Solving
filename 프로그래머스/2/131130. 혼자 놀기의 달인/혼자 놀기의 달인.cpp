#include <bits/stdc++.h>

using namespace std;

vector<int> cds;
vector<bool> visited;

int dfs(int idx) {
    if(visited[idx]) {
        return 0;
    }
    visited[idx] = true;
    return 1 + dfs(cds[idx]);
}

int solution(vector<int> cards) {
    cards.insert(cards.begin(), 0);
    cds = cards;
    const int n = cards.size();
    visited.resize(n, false);

    vector<int> nums;
    for(int i = 1; i < n; i++) {
        nums.push_back(dfs(i));
    }
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[0] * nums[1];
}