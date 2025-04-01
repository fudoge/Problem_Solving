#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if (a == 60 && b == 60 && c == 60) {
        cout << "Equilateral\n";
        return 0;
    }

    if (a + b + c != 180) {
        cout << "Error\n";
        return 0;
    }

    if (a == b || b == c || c == a) {
        cout << "Isosceles\n";
        return 0;
    }

    cout << "Scalene\n";

    return 0;
}