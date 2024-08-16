#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(s < 2) return {-1};
    if(n > s) return {-1};
    if(n == 1) return {s};
    if(n == s) {
        return vector<int>(n, 1);
    }
    
    vector<int> answer;
    int quotient = s / n;
    int remainder = s % n;
    for(int i = 0; i < n; ++i) {
        answer.push_back(quotient);
    }
    for(int i = n-1; i >= 0 && remainder > 0; --i) {
        answer[i]++;
        remainder--;
    }
    if(s == 1) answer[answer.size()-1]++;
    return answer;
}