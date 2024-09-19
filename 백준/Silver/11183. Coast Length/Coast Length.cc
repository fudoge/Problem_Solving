#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
    int n, m;
    int ans = 0;
    cin >> n >> m;

    vector<vector<int>> mat(n + 2, vector<int>(m + 2, 0));

    string s;
    for (int i = 1; i <= n; ++i)
    {   
        cin >> s;
        for (int j = 1; j <= m; ++j)
        {
            mat[i][j] = s[j - 1] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    mat[0][0] = 2;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n + 2 || ny >= m + 2)
                continue;
            if (mat[nx][ny] == 1)
            {
                ans++;
                continue;
            }
            if (mat[nx][ny] == 2)
                continue;
            q.push({nx, ny});
            mat[nx][ny] = 2;
        }
    }

    cout << ans << "\n";
    return 0;
}