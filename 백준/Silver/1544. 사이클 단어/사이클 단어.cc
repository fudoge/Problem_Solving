#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    unordered_map<string, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int start = 0; start < words[i].size(); start++) {
            string temp = "";
            for (int j = 0; j < words[i].size(); j++) {
                temp += words[i][(start + j) % words[i].size()];
            }
            if (mp[temp] > 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            mp[words[i]]++;
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
