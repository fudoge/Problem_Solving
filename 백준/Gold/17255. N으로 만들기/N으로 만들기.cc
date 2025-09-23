#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;
int ans = 0;

void dfs(string& key) {
    if (key.size() == 1) {
        ans++;
        return;
    }

    string leftPop = key.substr(1, key.size() - 1);
    string rightPop = key.substr(0, key.size() - 1);

    if (leftPop == rightPop) {
        dfs(leftPop);
    } else {
        dfs(leftPop);
        dfs(rightPop);
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;

    dfs(n);

    cout << ans << "\n";

    return 0;
}
