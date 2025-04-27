#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    int ans = 0;
    while(arr.size() > 1) {
        int loser = max_element(arr.begin(), arr.end()) - arr.begin();
        if(loser == 0) {
            ans += arr[loser] - arr[loser+1];
        } else if(loser == arr.size()-1) {
            ans += arr[loser] - arr[loser-1];
        } else {
            int right = arr[loser] - arr[loser+1];
            int left = arr[loser] - arr[loser-1];
            ans += min(right, left);
        }
        arr.erase(arr.begin() + loser);
    }

    cout << ans << '\n';

}
