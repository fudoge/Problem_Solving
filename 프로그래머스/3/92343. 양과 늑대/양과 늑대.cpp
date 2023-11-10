#include <bits/stdc++.h>

using namespace std;

int l[17], r[17], animal[17];
int n;
int answer = -1;

int vis[1 << 17];

void dfs(int state) {
    if(vis[state]) return;
    vis[state] = 1;
    
    int wolf = 0;
    int num = 0;
    
    for(int i = 0; i < n; i++) {
        if(state & (1 << i)) {
            num++;
            wolf += animal[i];
        }
    }

    if(wolf * 2 >= num) return;
    answer = max(answer, num-wolf);
    
    for(int i = 0; i < n; i++) {
        if(!(state & (1 << i))) continue;
        if(l[i] != -1) {
            dfs(state | 1 << l[i]);
        }
        if(r[i] != -1) {
            dfs(state | 1 << r[i]);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    fill(l, l+n, -1);
    fill(r, r+n, -1);
    
    for(int i = 0; i < n; i++) {
        animal[i] = info[i];
    }
    
    for(const auto &edge : edges) {
        int a = edge[0];
        int b = edge[1];
        
        if(l[a] != -1) r[a] = b;
        else l[a] = b;
    }
    
    dfs(1);
    return answer;
    
}