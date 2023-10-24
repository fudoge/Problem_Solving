#include <string>
#include <vector>
using namespace std;

int maxGap;
vector<int> answer(1,-1);

bool haveToChange(vector<int>& ryan) {
    for(int i=10; i>=0; i--) {
        if(ryan[i] > answer[i]) return true;
        else if(ryan[i] < answer[i]) return false;
    }   
}

void calcScore(vector<int>& ryan, vector<int>& apeach) {
    int ryanScore = 0, apeachScore = 0;
    for(int i=0; i<11; i++) {
        if(ryan[i] > apeach[i]) ryanScore += 10-i;
        else if(apeach[i] > 0) apeachScore += 10-i;
    }
    
    int gap = ryanScore-apeachScore;
    if(gap>0 && gap>=maxGap) {
        if(maxGap==gap && !haveToChange(ryan)) return;
        
        maxGap = gap;
        answer = ryan;        
    }
}

void solve(int index, int remains, vector<int>& ryan, vector<int>& apeach) {
    if(index==11 || remains==0) {
        ryan[10] += remains;
        calcScore(ryan, apeach);
        ryan[10] -= remains;
        return;
    }
    
    if(apeach[index] < remains) {
        ryan[index] += apeach[index]+1;
        solve(index+1, remains-apeach[index]-1,ryan,apeach);
        ryan[index] -= apeach[index]+1;
    }
    
    solve(index+1,remains,ryan,apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11,0);
    solve(0,n,ryan,info);

    return answer;
}