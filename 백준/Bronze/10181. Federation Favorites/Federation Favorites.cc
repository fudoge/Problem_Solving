#include <bits/stdc++.h>

#include <numeric>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    while ((cin >> x) && x != -1) {
        vector<int> a;
        for (int i = 1; i < x; i++) {
            if (x % i == 0) {
                a.emplace_back(i);
            }
        }
        if (accumulate(a.begin(), a.end(), 0) == x) {
            cout << x << " = ";
            for (int i = 0; i < a.size(); i++) {
                cout << a[i];
                if (i != a.size() - 1) {
                    cout << " + ";
                }
            }
            cout << "\n";
        } else {
            cout << x << " is NOT perfect.\n";
        }
    }

    return 0;
}