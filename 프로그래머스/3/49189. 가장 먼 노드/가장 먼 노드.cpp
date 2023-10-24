#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<bool> visited(n + 1, false);
    for (auto v : edge) {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    queue<int> q;
    q.push(1);
    visited[q.front()] = true;
    while (!q.empty()) {
        answer = q.size();
        for (int i = 0; i < answer; i++) {
            const int curr = q.front();
            q.pop();
            for (auto x : graph[curr]) {
                if (!visited[x]) {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
    return answer;
}
