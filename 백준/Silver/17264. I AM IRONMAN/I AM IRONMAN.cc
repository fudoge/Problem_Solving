#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;
    int w, l, g;
    cin >> w >> l >> g;

    int point = 0;
    unordered_map<string, bool> mp;

    for (int i = 0; i < p; i++) {
        string temp, result;
        cin >> temp >> result;

        mp[temp] = result == "W" ? true : false;
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (mp[s]) {
            point += w;
            if (point >= g) {
                cout << "I AM NOT IRONMAN!!\n";
                return 0;
            }
        } else {
            point = max(0, point - l);
        }
    }

    cout << "I AM IRONMAN!!\n";

    return 0;
}
