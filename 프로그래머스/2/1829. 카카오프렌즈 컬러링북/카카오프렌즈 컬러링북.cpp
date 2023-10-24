#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int bfs(int row, int col, vector<vector<int>> &picture, vector<vector<bool>> &visited) {
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    const int COLOR = picture[row][col];
    int colored_block = 1;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < visited.size() && ny >= 0 && ny < visited[0].size()) {
                if(!visited[nx][ny] && picture[nx][ny] == COLOR) {
                    visited[nx][ny] = true;
                    colored_block++;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return colored_block;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<bool>> visited (m, vector<bool>(n, false));
    
    int cnt = 0;
    int maxBlocks = INT_MIN;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && picture[i][j] != 0) {
                int blocks = bfs(i, j, picture, visited);
                cnt++;
                maxBlocks = max(maxBlocks, blocks);
            }
        }
    }
    return {cnt, maxBlocks};
}