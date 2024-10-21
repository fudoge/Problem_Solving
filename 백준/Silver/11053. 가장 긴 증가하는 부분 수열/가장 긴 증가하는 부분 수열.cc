#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> dp(n);
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    int maxLen = 0;
    for (int j = 0; j < i; ++j) {
      if (arr[i] > arr[j]) {
        maxLen = max(maxLen, dp[j]);
      }
    }
    dp[i] = maxLen + 1;
  }

  cout << *max_element(dp.begin(), dp.end()) << "\n";

  return 0;
}