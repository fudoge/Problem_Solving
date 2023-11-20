#include<bits/stdc++.h>

using namespace std;
int n;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
// 상하방향 코드: 0, 좌우방향 코드: 1
vector<int> direction = {0, 0, 1, 1};

int bfs(vector<int> start, vector<vector<int>> &board) {
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, 1e9)));
    dp[start[2]][0][0] = 0;
    
    //q에 {x좌표, y좌표, 방향순으로 넣음}
    queue<vector<int>> q;
    q.push(start);
    
    while(!q.empty()) {
        const auto curr = q.front();
        q.pop();
        int x = curr[0];
        int y = curr[1];
        int dir = curr[2];
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndir = direction[i];
            int dir_changed = dir ^ ndir;
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny] == 1) continue;
            
            int newCost = dp[dir][x][y] + 100 + 500 * dir_changed;
            if(newCost <= dp[ndir][nx][ny]) {
                dp[ndir][nx][ny] = newCost;
                q.push({nx, ny, ndir});
            }
        }
    }
    return min(dp[0][n-1][n-1], dp[1][n-1][n-1]);
}

int solution(vector<vector<int>> board) {
    n = board.size();
    return min(bfs({0, 0, 1}, board), bfs({0, 0, 0}, board));
}