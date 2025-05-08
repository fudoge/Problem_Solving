#pragma GCC optimize("O3", "unroll-loops");
static const int init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

using ti4 = tuple<int, int, int, int>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<ti4, vector<ti4>, greater<>> pq; // dist, turn, x, y
        pq.emplace(0, 0, 0, 0);

        while(!pq.empty()) {
            auto [curDist, turn, x, y] = pq.top();
            pq.pop();

            if(curDist > dist[x][y]) continue;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                int nextCostCand = max(curDist, moveTime[nx][ny]) + (turn%2) + 1;
                if(dist[nx][ny] > nextCostCand) {
                    dist[nx][ny] = nextCostCand;
                    pq.emplace(nextCostCand, turn+1, nx, ny);
                }
            }
        }

        return dist[n-1][m-1];
    }
};