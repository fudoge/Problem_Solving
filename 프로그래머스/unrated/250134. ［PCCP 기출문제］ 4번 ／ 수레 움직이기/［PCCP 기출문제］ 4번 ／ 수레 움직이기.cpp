#include <bits/stdc++.h>
using namespace std;

int n;
int m;

vector<int> times;
vector<vector<int>> board;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(pair<int, int> a, pair<int, int> b, int time, pair<int, int> &aEnd, pair<int, int> &bEnd, vector<vector<bool>> &aVisited, vector<vector<bool>> &bVisited)
{
    int ax = a.first;
    int ay = a.second;
    int bx = b.first;
    int by = b.second;
    bool aFinished = (ax == aEnd.first) && (ay == aEnd.second);
    bool bFinished = (bx == bEnd.first) && (by == bEnd.second);

    // cout << "a: {" << ax << ", " << ay << "}" << endl;
    // cout << "b: {" << bx << ", " << by << "}" << endl;
    // cout << "time: " << time << endl;

    if (aFinished && bFinished)
    {
        times.push_back(time);
        return;
    }

    aVisited[ax][ay] = true;
    bVisited[bx][by] = true;

    for (int i = 0; i < 4; i++)
    {
        int nax;
        int nay;
        if (aFinished)
        {
            nax = ax;
            nay = ay;
        }
        else
        {
            nax = ax + dx[i];
            nay = ay + dy[i];
            if (nax < 0 || nax >= n || nay < 0 || nay >= m)
                continue;
            if (aVisited[nax][nay])
                continue;
            if (board[nax][nay] == 5)
                continue;
            if (nax == bx && nay == by)
                continue;
        }

        for (int j = 0; j < 4; j++)
        {
            int nbx;
            int nby;
            if (bFinished)
            {
                nbx = bx;
                nby = by;
            }
            else
            {
                nbx = bx + dx[j];
                nby = by + dy[j];
                if (nbx < 0 || nbx >= n || nby < 0 || nby >= m)
                    continue;
                if (bVisited[nbx][nby])
                    continue;
                if (board[nbx][nby] == 5)
                    continue;
                // 같은 장소에는 갈 수 없음
                if (nax == nbx && nay == nby)
                    continue;
            }

            dfs({nax, nay}, {nbx, nby}, time + 1, aEnd, bEnd, aVisited, bVisited);
        }
    }
    aVisited[ax][ay] = false;
    bVisited[bx][by] = false;
}

int solution(vector<vector<int>> maze)
{
    n = maze.size();
    m = maze[0].size();

    pair<int, int> rStart;
    pair<int, int> rEnd;
    pair<int, int> bStart;
    pair<int, int> bEnd;

    vector<vector<bool>> rVisited;
    vector<vector<bool>> bVisited;
    board.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 1)
            {
                rStart = {i, j};
            }
            else if (maze[i][j] == 2)
            {
                bStart = {i, j};
            }
            else if (maze[i][j] == 3)
            {
                rEnd = {i, j};
            }
            else if (maze[i][j] == 4)
            {
                bEnd = {i, j};
            }
            board[i][j] = maze[i][j];
        }
    }

    rVisited.resize(n, vector<bool>(m, false));
    bVisited.resize(n, vector<bool>(m, false));
    dfs(rStart, bStart, 0, rEnd, bEnd, rVisited, bVisited);
    rVisited.resize(n, vector<bool>(m, false));
    bVisited.resize(n, vector<bool>(m, false));
    //cout << "========" << endl;
    dfs(bStart, rStart, 0, bEnd, rEnd, bVisited, rVisited);

    if (times.size() == 0)
        return 0;
    return *min_element(times.begin(), times.end());
}