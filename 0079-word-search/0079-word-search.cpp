#pragma GCC optimize("03", "unroll-loops");

static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
private:
    bool found;
    int n;
    int m;
public:
    void search(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int x, int y, int idx) {
        //cout << x << " " << y << " " << idx << "\n";
        visited[x][y] = true;
        if(idx >= word.size()) {
            found = true;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;

            if(word[idx] == board[nx][ny]) {
                search(board, visited, word, nx, ny, idx+1);
            }
        }

        visited[x][y] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> visited (n, vector<bool>(m, false));
        found = false;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    search(board, visited, word, i, j, 1);
                    if(found) return true;
                }
            }
        }

        return false;
    }
};