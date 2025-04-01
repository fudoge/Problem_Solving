#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n);
        for (auto &i : w) cin >> i;
        int sum = accumulate(w.begin(), w.end(), 0);
        if (sum == 0) {
            cout << "Equilibrium\n";
        } else if (sum < 0) {
            cout << "Left\n";
        } else if (sum > 0) {
            cout << "Right\n";
        }
    }

    return 0;
}