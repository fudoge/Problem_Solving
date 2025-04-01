#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        while (l < r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    for (const auto &elem : a) {
        cout << elem << " ";
    }
    cout << "\n";

    return 0;
}