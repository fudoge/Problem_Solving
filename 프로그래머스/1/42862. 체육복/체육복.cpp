#include<bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> students(n+2, 1);
    students[0] = 0;
    students[n+1] = 0;
    for(const auto& lostman : lost) {
        students[lostman]--;
    }
    for(const auto& reserveman : reserve) {
        students[reserveman]++;
    }

    for(int i = 1; i <= n; i++) {
        if(students[i] == 0) {
            if(students[i-1] > 1) {
                students[i-1]--;
                students[i]++;
            } else if(students[i+1] > 1) {
                students[i+1]--;
                students[i]++;
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(students[i] > 0) {
            cnt++;
        }
    }

    return cnt;
}