#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> tangerines;
    for(const auto &t : tangerine) {
        tangerines[t]++;
    }
    
    vector<int> table;
    for(const auto &tange : tangerines) {
        table.push_back(tange.second);
    }
    
    sort(table.begin(), table.end(), greater<int>());
    
    int sum = 0;
    int count = 0;
    for(const auto &t : table) {
        sum += t;
        count++;
        if(sum >= k) break;
    }
    
    return count;
}