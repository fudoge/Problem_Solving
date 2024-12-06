#include <bits/stdc++.h>

using namespace std;

int n, s;
int arr[20];

int ans = 0;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int mask = (1 << n) - 1;
  for (int i = 1; i <= mask; ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j))
        sum += arr[j];
    }
    if (sum == s)
      ans++;
  }

  cout << ans << "\n";

  return 0;
}