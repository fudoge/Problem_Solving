#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int target = priorities[location];
    
    queue<int> q;
    vector<int> greatest;
    for(int p : priorities) {
        q.push(p);
        greatest.push_back(p);
    }

    sort(greatest.begin(), greatest.end(), greater<int>());
    int idx = 0;
    
    while(!q.empty()) {
        while(q.front() != greatest[idx]) {
            q.push(q.front());
            q.pop();
            if(location == 0) {
                location = q.size();
            }
            location--;
        }
        if(location == 0) {
            answer++;
            break;
        }
        q.pop();
        idx++;
        answer++;
        location--;
    }
    
    return answer;
}
