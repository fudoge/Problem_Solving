#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int ans = 0;
    // h
    for (int col = 0; col < n; col++) {
        bool available = true;
        int last = mat[0][col];
        int maxHeight = last;
        int streak = 1;
        vector<pii> arr;
        for (int i = 1; i < n; i++) {
            if (mat[i][col] == last) {
                streak++;
            } else {
                arr.emplace_back(last, streak);
                last = mat[i][col];
                streak = 1;
            }
            maxHeight = max(maxHeight, last);
        }
        arr.emplace_back(last, streak);

        if (arr.size() == 1) {
            ans++;
            continue;
        }

        if (arr[1].first - arr[0].first > 1 ||
            (arr[0].first < arr[1].first && l > arr[0].second)) {
            available = false;
        }
        for (int i = 1; available && i < arr.size() - 1; i++) {
            if (arr[i].first == maxHeight) continue;
            int required = 0;
            if (arr[i - 1].first > arr[i].first) {
                if (arr[i - 1].first - arr[i].first > 1) available = false;
                required += l;
            }
            if (arr[i + 1].first > arr[i].first) {
                if (arr[i + 1].first - arr[i].first > 1) available = false;
                required += l;
            }
            if (required > arr[i].second) {
                available = false;
            }
        }
        if (arr[arr.size() - 1].first - arr[arr.size() - 2].first > 1 ||
            (arr[arr.size() - 1].first < arr[arr.size() - 2].first &&
             l > arr[arr.size() - 1].second)) {
            available = false;
        }

        if (available) {
            ans++;
        }
    }

    // v
    for (int row = 0; row < n; row++) {
        bool available = true;
        int last = mat[row][0];
        int maxHeight = last;
        int streak = 1;
        vector<pii> arr;
        for (int i = 1; i < n; i++) {
            if (mat[row][i] == last) {
                streak++;
            } else {
                arr.emplace_back(last, streak);
                last = mat[row][i];
                streak = 1;
            }
            maxHeight = max(maxHeight, last);
        }
        arr.emplace_back(last, streak);

        if (arr.size() == 1) {
            ans++;
            continue;
        }

        if (arr[1].first - arr[0].first > 1 ||
            (arr[0].first < arr[1].first && l > arr[0].second)) {
            available = false;
        }
        for (int i = 1; available && i < arr.size() - 1; i++) {
            if (arr[i].first == maxHeight) continue;
            int required = 0;
            if (arr[i - 1].first > arr[i].first) {
                if (arr[i - 1].first - arr[i].first > 1) available = false;
                required += l;
            }
            if (arr[i + 1].first > arr[i].first) {
                if (arr[i + 1].first - arr[i].first > 1) available = false;
                required += l;
            }
            if (required > arr[i].second) {
                available = false;
            }
        }
        if (arr[arr.size() - 1].first - arr[arr.size() - 2].first > 1 ||
            (arr[arr.size() - 1].first < arr[arr.size() - 2].first &&
             l > arr[arr.size() - 1].second)) {
            available = false;
        }

        if (available) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
