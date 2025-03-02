#include <bits/stdc++.h>

#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    int lensum = 0;
    int curlen = 1;
    int next = 9;
    int streak = 0;

    int num = 1;
    while (true) {
        if (lensum + curlen >= n) break;
        lensum += curlen;
        streak++;
        num++;
        if (streak == next) {
            curlen++;
            streak = 0;
            next *= 10;
        }
    }

    string str = to_string(num);
    cout << str[n - lensum - 1] << "\n";

    return 0;
}