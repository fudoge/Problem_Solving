#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> bridge;

    int time = 0;
    int bridgeWeight = 0;

    for(int i = 0; i < truck_weights.size(); i++){
        time++;
        if(time == bridge.front().second + bridge_length){
            bridgeWeight -= bridge.front().first;
            bridge.pop();
        }
        while(bridgeWeight + truck_weights[i] > weight){
            time = bridge.front().second + bridge_length;
            bridgeWeight -= bridge.front().first;
            bridge.pop();
        }
        bridgeWeight += truck_weights[i];
        bridge.push({truck_weights[i], time});
    }

    time = bridge.back().second + bridge_length;

    return time;
}