#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int xidx = 0;
    while (xidx < str.size() && str[xidx] != 'x') xidx++;
    if (xidx == str.size()) {
        cout << "0\n";
        return 0;
    }
    int signidx = xidx;
    while (signidx > 0 && !(str[signidx] == '-' || str[signidx] == '+')) {
        signidx--;
    }

    if (xidx == signidx) {
        cout << "1\n";
    } else if (xidx - signidx == 1 &&
               (str[signidx] < '0' || str[signidx] > '9')) {
        cout << stoi(string(1, str[signidx]) + "1") << "\n";
    } else {
        cout << stoi(str.substr(signidx, xidx - signidx)) << "\n";
    }

    return 0;
}
