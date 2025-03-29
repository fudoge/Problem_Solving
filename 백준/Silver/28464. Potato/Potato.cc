#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    sort(a.begin(), a.end(), greater<>());
    int m = (n / 2) + n % 2;

    int A = accumulate(a.begin(), a.begin() + m, 0);
    int B = accumulate(a.begin() + m, a.end(), 0);
    cout << B << " " << A << "\n";
    return 0;
}