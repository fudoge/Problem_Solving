#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph;
unordered_map<int, bool> is_summit;

// 거리 테이블을 반환하는 다익스트라
vector<int> dijkstra(int gate) {
    vector<int> intensities (graph.size()+1, 1e9);
    intensities[gate] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, gate});
    
    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        int curr_intensity = curr.first;
        int curr_node = curr.second;
        
        if(is_summit[curr_node]) break;
        for(const auto& next : graph[curr_node]) {
            int next_node = next.first;
            int next_intensity = max(next.second, curr_intensity);
            
            if(next_intensity < intensities[next_node]) {
                intensities[next_node] = next_intensity;
                pq.push({next_intensity, next_node});
            }
        }
    }
    return intensities;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    
    graph.resize(n+1);
    unordered_map<int, bool> is_gate;
    for(const auto& gate : gates){
        is_gate[gate] = true;
    }
    for(const auto& summit : summits){
        is_summit[summit] = true;
    }
    for(const auto& path : paths) {
        int a = path[0];
        int b = path[1];
        int cost = path[2];
        
        //gate는 목적지로 넣지 않음
        if(is_gate[a]) {
            if(!is_gate[b]) {
                graph[a].push_back({b, cost});
            }
        } else if(is_gate[b]) {
            graph[b].push_back({a, cost});
        } else {
            graph[a].push_back({b, cost});
            graph[b].push_back({a, cost});
        }
        
    }
    
    // 정상에서 다른 곳으로 가지 못하게
    for(const auto& summit : summits) {
        graph[summit] = {};
    }
    
    //각 출발점마다 최단거리 구하고 갱신..
    int min_intensity = INT_MAX;
    int min_summit;
    for (const auto &gate: gates) {
        vector<int> intens = dijkstra(gate);
        for(const auto& summit : summits) {
            int intensity = intens[summit];
            if(min_intensity > intensity || min_intensity == intensity && min_summit > summit) {
                min_summit = summit;
                min_intensity = intensity;
            }
        }
    }
    
    return {min_summit, min_intensity};
}
