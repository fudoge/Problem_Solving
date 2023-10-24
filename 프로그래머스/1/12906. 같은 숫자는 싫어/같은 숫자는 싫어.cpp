#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    deque<int> q;
    for (int i : arr) {
        if (q.empty() || i != q.back()) {
            q.push_back(i);
        }
    }
    int size = q.size();
    for (int i = 0; i < size; i++) {
        int a = q.front();
        q.pop_front();
        answer.push_back(a);
    }
    return answer;
}
