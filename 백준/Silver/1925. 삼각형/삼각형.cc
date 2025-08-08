#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll dist2(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool collinear(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll ax = x2 - x1, ay = y2 - y1;
    ll bx = x3 - x1, by = y3 - y1;
    return ax * by - ay * bx == 0;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (((x1 == x2) && (y1 == y2)) || (x2 == x3 && y2 == y3) ||
        (x3 == x1 && y3 == y1)) {
        cout << "X\n";
        return 0;
    }
    if (collinear(x1, y1, x2, y2, x3, y3)) {
        cout << "X\n";
        return 0;
    }

    int side1 = dist2(x1, y1, x2, y2);
    int side2 = dist2(x2, y2, x3, y3);
    int side3 = dist2(x3, y3, x1, y1);

    vector<int> sides = {side1, side2, side3};
    sort(sides.begin(), sides.end());

    if (sides[0] == sides[2]) {
        cout << "JungTriangle\n";
        return 0;
    }

    if (sides[0] == sides[1]) {
        if (sides[2] == 2 * sides[0]) {
            cout << "Jikkak2Triangle\n";
        } else {
            cout << "Dunkak2Triangle\n";
        }
        return 0;
    }

    if (sides[1] == sides[2]) {
        cout << "Yeahkak2Triangle\n";
        return 0;
    }

    ll x = sides[0] + sides[1] - sides[2];
    if (x > 0) {
        cout << "YeahkakTriangle\n";
    } else if (x == 0) {
        cout << "JikkakTriangle\n";
    } else {
        cout << "DunkakTriangle\n";
    }

    return 0;
}
