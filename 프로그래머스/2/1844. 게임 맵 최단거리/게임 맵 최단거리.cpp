#include <vector>
#include <deque>
using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int bfs(int n, int m, vector<vector<int>> maps) {
    int distance = 1;
    int x;
    int y;
    deque<vector<int>> q;
    q.push_back({0, 0});
    while (!q.empty()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            x = q.front().at(0);
            y = q.front().at(1);
            q.pop_front();
            if (x == n-1 && y == m-1) {
                return distance;
            }
            for (int j = 0; j < 4; j++) {
                int nx = x + dx.at(j);
                int ny = y + dy.at(j);
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1) {
                    q.push_back({nx, ny});
                    maps[nx][ny] = distance + 1;
                }
            }
        }
        distance++;
    }
    return -1;
}

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps.at(0).size();
    int answer = bfs(n, m, maps);
    return answer;
}
