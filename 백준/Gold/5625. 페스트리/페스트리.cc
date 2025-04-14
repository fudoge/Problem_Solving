#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> dx(1000001, 0), dy(1000001, 0);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int xa = min({x1, x2, x3});
        int xb = max({x1, x2, x3});
        int ya = min({y1, y2, y3});
        int yb = max({y1, y2, y3});

        dx[xa + 1]++;
        dx[xb]--;
        dy[ya + 1]++;
        dy[yb]--;
    }
    vector<int> xaxis(1000001, 0), yaxis(1000001, 0);
    for (int i = 1; i <= 1000000; i++) {
        xaxis[i] = xaxis[i - 1] + dx[i];
        yaxis[i] = yaxis[i - 1] + dy[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char axis;
        char equalsign;
        int k;
        cin >> axis >> equalsign >> k;

        if (axis == 'x') {
            cout << xaxis[k] << "\n";
        } else {
            cout << yaxis[k] << "\n";
        }
    }

    return 0;
}