#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int getRoot(int x, vector<int> &parent) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x], parent);
}

void merge(int u, int v, vector<int> &parent) {
    int uRoot = getRoot(u, parent);
    int vRoot = getRoot(v, parent);

    if (uRoot == vRoot) return;
    if (uRoot < vRoot) {
        parent[vRoot] = uRoot;
    } else {
        parent[uRoot] = vRoot;
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int maxid = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && mat[i][j] != 0) {
                maxid++;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                mat[i][j] = maxid;
                visited[i][j] = true;
                while (!q.empty()) {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (mat[nx][ny] == 1 && !visited[nx][ny]) {
                            mat[nx][ny] = maxid;
                            visited[nx][ny] = true;
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> adj(maxid + 1);
    vector<array<int, 3>> edges;  // <dist, u, v>

    for (int i = 0; i < n; i++) {
        int last_ground = 0;
        for (int j = 0; j < m;) {
            if (mat[i][j] != 0) {
                last_ground = mat[i][j];
                while (j < m && mat[i][j] == last_ground) j++;
            } else {
                int start = j;
                while (j < m && mat[i][j] == 0) j++;
                if (last_ground != 0 && j != m && j - start >= 2) {
                    edges.push_back({j - start, mat[i][j], last_ground});
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int last_ground = 0;
        for (int i = 0; i < n;) {
            if (mat[i][j] != 0) {
                last_ground = mat[i][j];
                while (i < n && mat[i][j] == last_ground) i++;
            } else {
                int start = i;
                while (i < n && mat[i][j] == 0) i++;
                if (last_ground != 0 && i != n && i - start >= 2) {
                    edges.push_back({i - start, mat[i][j], last_ground});
                }
            }
        }
    }

    int ans = 0;
    vector<int> parent(maxid + 1);
    iota(parent.begin(), parent.end(), 0);
    sort(edges.begin(), edges.end());
    for (const auto &edge : edges) {
        int u = edge[1], v = edge[2];
        if (getRoot(u, parent) != getRoot(v, parent)) {
            ans += edge[0];
            merge(u, v, parent);
        }
    }

    for (int i = 1; i <= maxid; i++) {
        if (getRoot(i, parent) != 1) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << ans << "\n";
    return 0;
}