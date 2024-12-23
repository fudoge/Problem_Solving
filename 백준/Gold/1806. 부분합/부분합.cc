#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, s;
  int arr[100000];
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int ans = INT_MAX;
  int l = 0;
  int sum = 0;
  for (int r = 0; r < n; ++r) {
    sum += arr[r];
    while (sum >= s && l <= r) {
      ans = min(ans, r - l + 1);
      sum -= arr[l];
      ++l;
    }
  }

  if (ans == INT_MAX)
    ans = 0;
  cout << ans << "\n";

  return 0;
}