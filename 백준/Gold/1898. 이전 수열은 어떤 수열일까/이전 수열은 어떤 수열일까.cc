#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> numToIdx(n + 1);
    for (int i = 0; i < n; i++) {
        numToIdx[a[i]] = i;
    }

    vector<bool> occupied(n, false);
    vector<int> partnercount(n + 1, 3);
    partnercount[n] = 2;
    partnercount[1] = 2;
    partnercount[0] = 0;
    vector<int> ans(n);
    for (int i = n; i > 0; i--) {
        int leastIdx = 0;
        int partner = 0;
        for (int j = max(i - 1, 1); j <= min(i + 1, n); j++) {
            if (!occupied[numToIdx[j]] && partnercount[j] == 1) {
                leastIdx = numToIdx[j];
                partner = j;
                break;
            }
            if (!occupied[numToIdx[j]] && numToIdx[j] > leastIdx) {
                leastIdx = numToIdx[j];
                partner = j;
            }
            // cout << i << ")" << j << " " << leastIdx << " " << partner <<
            // "\n";
        }

        ans[leastIdx] = i;
        occupied[leastIdx] = true;
        for (int j = max(i - 1, 1); j <= min(i + 1, n); j++) {
            partnercount[j]--;
        }
        // cout << partner << " " << leastIdx << "\n";
    }

    for (const auto &elem : ans) {
        cout << elem << "\n";
    }

    return 0;
}