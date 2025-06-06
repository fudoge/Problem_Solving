#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void normalize(int &a, int &b) {
    int GCD = gcd(a, b);
    a /= GCD;
    b /= GCD;
}

auto comp = [](const array<int, 2> &a, const array<int, 2> &b) -> bool {
    return (long long)a[0] * b[1] < (long long)b[0] * a[1];
};

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<array<array<int, 2>, 2>> segments(n);
    vector<bool> isAlive(n, true);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        normalize(x1, y1);
        normalize(x2, y2);
        array<int, 2> pointA = {x1, y1};
        array<int, 2> pointB = {x2, y2};
        if (comp(pointA, pointB)) {
            segments[i][0] = pointA;
            segments[i][1] = pointB;
        } else {
            segments[i][1] = pointA;
            segments[i][0] = pointB;
        }
    }

    int m;
    cin >> m;
    vector<array<int, 2>> lasers(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        normalize(a, b);
        lasers[i] = {a, b};
    }
    sort(lasers.begin(), lasers.end(), comp);

    int ans = n;
    for (int i = 0; i < n; i++) {
        auto &a = segments[i][0];
        auto &b = segments[i][1];

        if (a[0] == b[0] && a[1] == b[1]) {
            int idx = lower_bound(lasers.begin(), lasers.end(), a, comp) -
                      lasers.begin();
            if (idx < m && lasers[idx][0] == a[0] && lasers[idx][1] == b[1]) {
                ans--;
                continue;
            }
        }

        int idx1 =
            lower_bound(lasers.begin(), lasers.end(), a, comp) - lasers.begin();
        int idx2 =
            upper_bound(lasers.begin(), lasers.end(), b, comp) - lasers.begin();
        if (idx1 < idx2) {
            ans--;
        }
    }

    cout << ans << "\n";

    return 0;
}