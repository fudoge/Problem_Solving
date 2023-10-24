#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    int day = 0;
    int count = 0;
    
    while (!progresses.empty()) {
        if (progresses.front() + day * speeds.front() >= 100) {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            count++;
        } else {
            if (count > 0) {
                answer.push_back(count);
                count = 0;
            }
            day++;
        }
    }
    
    if (count > 0) {
        answer.push_back(count);
    }
    
    return answer;
}
