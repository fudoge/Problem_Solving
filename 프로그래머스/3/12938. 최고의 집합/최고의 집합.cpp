#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(s < n) return {-1};

    vector<int> answer(n, s / n);
    for(int i = 0; i < s % n; ++i) {
        answer[n-1-i]++;
    }

    return answer;
}