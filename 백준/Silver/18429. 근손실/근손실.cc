#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = {x, i};
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    do {
        int w = 500;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            w += arr[i].first - k;
            if (w < 500) {
                flag = false;
                break;
            }
        }
        if (w < 500) flag = false;
        if (flag) ans++;
    } while (next_permutation(arr.begin(), arr.end()));

    cout << ans << "\n";

    return 0;
}
