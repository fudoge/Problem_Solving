#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    int v;
    cin >> v;
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == v) ans++;
    }
    
    cout << ans << "\n";
}