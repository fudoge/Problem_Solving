#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << 10000 + a * 1000 << "\n";
    } else if (a == b || b == c || c == a) {
        if (a == b) {
            cout << 1000 + a * 100 << "\n";
        } else if (b == c) {
            cout << 1000 + b * 100 << "\n";
        } else {
            cout << 1000 + c * 100 << "\n";
        }
    } else {
        cout << max({a, b, c}) * 100 << "\n";
    }

    return 0;
}