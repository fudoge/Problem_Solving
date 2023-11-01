#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(), data.end(), [col](const auto& a, const auto &b) {
        if(a[col-1] == b[col-1]) {
            return a[0] > b[0];
        }
        return a[col-1] < b[col-1];
    });
    
    vector<int> nums;
    for(int i = row_begin-1; i < row_end; i++) {
        int x = 0;
        for(const auto &num : data[i]) {
            x += num%(i+1);
        }
        nums.push_back(x);
    }
    
    int answer = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        answer = answer ^ nums[i];
    }
    
    return answer;
}