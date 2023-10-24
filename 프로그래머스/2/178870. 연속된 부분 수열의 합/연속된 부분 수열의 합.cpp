#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<int>> answer;
    const int n = sequence.size();
    int left = 0;
    int right = 0;
    int currentSum = 0;
    
    while (right < n) {
        currentSum += sequence[right];
        
        while (currentSum > k && left <= right) {
            currentSum -= sequence[left];
            left++;
        }
        
        if (currentSum == k) {
            answer.push_back({left, right});
        }
        right++;
    }
    
    sort(answer.begin(), answer.end(), [](const auto &a, const auto &b) {
        if(a[1]-a[0] == b[1]-b[0]) {
            return a[0] < b[0];
        }
        return a[1]-a[0] < b[1]-b[0];
    });
    
    return answer[0];
}