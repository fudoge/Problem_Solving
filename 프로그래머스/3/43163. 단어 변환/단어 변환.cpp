#include <bits/stdc++.h>

using namespace std;
int n;

bool available(string &a, string &b) {
    int err = 0;
    
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) err++;
    }
    
    return err == 1;
    
}

int solution(string begin, string target, vector<string> words) {
    n = begin.size();
    const int m = words.size() + 1;
    
    words.insert(words.begin(), begin);
    
    int from = 0;
    int to = 0;
    
    for(int i = 1; i < m; i++) {
        if(target == words[i]) {
            to = i;
            break;
        }
    }
    
    if(!to) return 0;
    
    vector<vector<int>> graph(m, vector<int>());
    for(int i = 0; i < m-1; i++) {
        for(int j = i+1; j < m; j++) {
            if(available(words[i], words[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    vector<bool> visited(m, false);
    queue<pair<int, int>> q; // idx, times
    q.push({0, 0});
    visited[0] = true;
    
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        if(curr.first == to) return curr.second;
        
        for(const auto &next : graph[curr.first]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push({next, curr.second+1});
            }
        }
    }
    
    return 0;
}