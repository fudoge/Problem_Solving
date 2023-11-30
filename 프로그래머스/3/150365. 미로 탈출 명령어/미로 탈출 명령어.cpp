#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, -1, 1, 0};
vector<char> dir = {'d', 'l', 'r', 'u'};

pair<int, int> from;
pair<int, int> to;
vector<vector<vector<bool>>> visited;

int rowSize;
int colSize;

int getDiff(pair<int, int> a, pair<int, int> b) {
    return abs(b.first - a.first) + abs(b.second - a.second);
}

string dfs(pair<int, int> curr, int left, string prefix) {
    if (getDiff(curr, to) > left)
        return "";

    int x = curr.first;
    int y = curr.second;

    visited[x][y][left] = true;

    //cout << x << " " << y << " " << left << " " << prefix << endl;

    if (left == 0) {
        if(x == to.first && y == to.second)
            return prefix;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        string str = prefix + dir[i];

        if (nx < 0 || ny < 0 || nx >= rowSize || ny >= colSize)
            continue;
        if (visited[nx][ny][left])
            continue;
        string s = dfs({nx, ny}, left - 1, str);
        if (s.size() != 0)
            return s;
    }

    return "impossible";
}

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    int diff = getDiff({x, y}, {r, c});
    if (diff > k || diff % 2 != k % 2)
        return "impossible";

    rowSize = n;
    colSize = m;

    from = {x - 1, y - 1};
    to = {r - 1, c - 1};

    visited.resize(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));

    return dfs(from, k, "");
}