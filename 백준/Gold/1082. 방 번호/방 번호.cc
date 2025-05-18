#include <bits/stdc++.h>

using namespace std;

int n, minimum;
vector<string> numtostr = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

bool ge(const string& a, const string& b) {
    if (a.size() < b.size()) return false;
    if (a.size() > b.size()) return true;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) return false;
        if (a[i] > b[i]) return true;
    }

    return true;
}

string solve(int remain, vector<int>& p, vector<string>& dp) {
    if (remain < minimum) {
        return "";
    }

    if (dp[remain] != ".") {
        return dp[remain];
    }

    string res = "";
    for (int i = n - 1; i >= 0; i--) {
        if (remain >= p[i]) {
            string temp = numtostr[i] + solve(remain - p[i], p, dp);
            if (ge(temp, res)) {
                res = temp;
            }
        }
    }
    return dp[remain] = res;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n;
    vector<int> p(n);
    for (auto& i : p) cin >> i;
    cin >> m;
    minimum = *min_element(p.begin(), p.end());

    vector<string> dp(m + 1, ".");

    string res = "";
    for (int i = n - 1; i > 0; i--) {
        if (m >= p[i]) {
            string temp = numtostr[i] + solve(m - p[i], p, dp);
            if (ge(temp, res)) {
                res = temp;
            }
        }
    }
    if (res == "") {
        cout << "0\n";
    } else {
        cout << res << "\n";
    }

    return 0;
}