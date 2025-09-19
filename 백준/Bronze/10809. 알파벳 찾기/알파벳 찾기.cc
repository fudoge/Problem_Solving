#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> pos(26, -1);
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (pos[ch - 'a'] == -1) {
            pos[ch - 'a'] = i;
        }
    }

    for (const auto &elem : pos) {
        cout << elem << " ";
    }
    cout << "\n";

    return 0;
}
