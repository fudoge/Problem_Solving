#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> umen, dmen;
    vector<int> uwomen, dwomen;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0)
            umen.emplace_back(x);
        else
            dmen.emplace_back(-x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0)
            uwomen.emplace_back(x);
        else
            dwomen.emplace_back(-x);
    }

    sort(umen.begin(), umen.end());
    sort(dmen.begin(), dmen.end());
    sort(uwomen.begin(), uwomen.end());
    sort(dwomen.begin(), dwomen.end());

    int ans = 0;
    int j = 0;
    for (int i = 0; i < uwomen.size() && j < dmen.size(); i++) {
        while (j < dmen.size() && dmen[j] <= uwomen[i]) {
            j++;
        }
        if (j == dmen.size()) break;
        ans++;
        j++;
    }

    j = 0;
    for (int i = 0; i < umen.size() && j < dwomen.size(); i++) {
        while (j < dwomen.size() && dwomen[j] <= umen[i]) {
            j++;
        }
        if (j == dwomen.size()) break;
        ans++;
        j++;
    }

    cout << ans << "\n";

    return 0;
}