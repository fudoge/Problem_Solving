#include <bits/stdc++.h>

using namespace std;

int solve(string str, int by) {
    int n = str.size();
    
    for(int i = 0; i < str.size(); i+=by) {
        const string init = str.substr(i, by);
        // cout << "by: " << by << " init: " << init << endl;
        int cnt = 1;
        
        bool flag = false;
        while(i + by <= str.size() && str.substr(i+by, by) == init) {
            i += by;
            n -= by;
            cnt++;
            flag = true;
        }
        if(flag) i-=by;
        if (cnt > 1) {
            while (cnt > 0) {
                cnt /= 10;
                n++;
            }
        }
    }
    // cout << "by: " << by << " len: " << n << endl;
    return n;
}

int solution(string s) {
    int answer = s.size();
    
    for (int i = 1; i <= s.size()/2; i++) {
        answer = min(answer, solve(s, i));
    }
    
    return answer;
}
