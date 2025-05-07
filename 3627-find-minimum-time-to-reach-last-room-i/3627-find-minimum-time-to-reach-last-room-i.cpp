#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

using tiii = tuple<int, int, int>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<tiii, vector<tiii>, greater<>> pq; // time, x, y;
        dist[0][0] = moveTime[0][0];
        pq.emplace(0, 0, 0);

        while(!pq.empty()) {
            auto [curTime, x, y] = pq.top();
            pq.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(dist[nx][ny] > max(moveTime[nx][ny], curTime)+1) {
                    dist[nx][ny] = max(moveTime[nx][ny], curTime)+1;
                    pq.emplace(dist[nx][ny], nx, ny);
                }
            }
        }

        return dist[n-1][m-1];
    }
};