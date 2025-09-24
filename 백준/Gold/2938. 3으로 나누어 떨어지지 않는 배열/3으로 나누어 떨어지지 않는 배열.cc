#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a;
    vector<vector<int>> mods(3);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 3 == 0)
            mods[0].emplace_back(x);
        else if (x % 3 == 1)
            mods[1].emplace_back(x);
        else
            mods[2].emplace_back(x);
    }

    if (mods[1].size() > 0 && mods[2].size() > 0 && mods[0].size() == 0) {
        cout << "-1\n";
        return 0;
    }
    if (mods[0].size() > mods[1].size() + mods[2].size() + 1) {
        cout << "-1\n";
        return 0;
    }

    bool middleZero = false;
    if (mods[1].size() > 0 && mods[2].size() > 0) {
        middleZero = true;
    }

    int zeroPtr = 0;
    if ((!middleZero && zeroPtr < mods[0].size()) ||
        (middleZero && zeroPtr < mods[0].size() - 1)) {
        cout << mods[0][zeroPtr] << " ";
        zeroPtr++;
    }
    for (int i = 0; i < mods[1].size(); i++) {
        cout << mods[1][i] << " ";
        if ((!middleZero && zeroPtr < mods[0].size()) ||
            (middleZero && (zeroPtr < mods[0].size() - 1) ||
             (i == mods[1].size() - 1 && zeroPtr < mods[0].size()))) {
            cout << mods[0][zeroPtr] << " ";
            zeroPtr++;
        }
    }
    for (int i = 0; i < mods[2].size(); i++) {
        cout << mods[2][i] << " ";
        if (zeroPtr < mods[0].size()) {
            cout << mods[0][zeroPtr] << " ";
            zeroPtr++;
        }
    }

    cout << "\n";

    return 0;
}
