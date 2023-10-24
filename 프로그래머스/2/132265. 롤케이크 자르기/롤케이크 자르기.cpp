#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<int, int> brother;
    unordered_set<int> brotherSet;

    int answer = 0;
    const int n = topping.size();

    for(int i = 0; i < n; i++) {
        brother[topping[i]]++;
        brotherSet.insert(topping[i]);
    }

    unordered_map<int, int> cheolsu;
    unordered_set<int> cheolsuSet;

    for(int i = 0; i < n; i++) {
        cheolsu[topping[i]]++;
        cheolsuSet.insert(topping[i]);
        brother[topping[i]]--;
        if(brother[topping[i]] <= 0) {
            brotherSet.erase(topping[i]);
        } 
        if(cheolsuSet.size() == brotherSet.size()) {
            answer++;
        }
    }

    return answer;
}