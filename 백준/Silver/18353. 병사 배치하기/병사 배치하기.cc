#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  vector<int> dp(n, 0);
  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    int last_idx = i;
    for (int j = 0; j < i; ++j) {
      if (dp[j] > dp[last_idx] && arr[j] > arr[i]) {
        last_idx = j;
      }
    }
    dp[i] = dp[last_idx] + 1;
  }

  cout << n - *max_element(dp.begin(), dp.end()) << "\n";

  return 0;
}