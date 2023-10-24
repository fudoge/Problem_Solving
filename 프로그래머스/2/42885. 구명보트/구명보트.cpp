#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int curr = 0;
    int cnt = 0;

    deque<int> dq;
    for(int person : people) {
        dq.push_back(person);
    }
    
    while(!dq.empty()) {
        if(dq.size() == 1) {
            answer++;
            break;
        }
        if(dq.back() + dq.front() > limit) {
            dq.pop_back();
        } else {
            dq.pop_back();
            dq.pop_front();
        }
        answer++;
    }
    
    return answer;
}