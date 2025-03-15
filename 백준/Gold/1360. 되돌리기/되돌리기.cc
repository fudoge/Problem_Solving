#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<string, int>> arr;
    arr.push_back({"", 0});

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "type") {
            char ch;
            int time;
            cin >> ch >> time;
            arr.push_back({arr.back().first + ch, time});
        } else {
            int backtime;
            int time;
            cin >> backtime >> time;

            int startTime = time - backtime;
            int referenceIdx = 0;
            for (int i = 1; i < arr.size(); i++) {
                if (arr[i].second >= startTime) break;
                referenceIdx = i;
            }

            arr.push_back({arr[referenceIdx].first, time});
        }
    }

    cout << arr.back().first << "\n";

    return 0;
}