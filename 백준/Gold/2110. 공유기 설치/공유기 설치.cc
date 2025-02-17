#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  cin >> n >> c;
  vector<int> arr(n);
  for (int &x : arr) {
    cin >> x;
  }

  sort(arr.begin(), arr.end());
  int lo = 1, hi = arr.back() - arr[0];

  int ans = 0;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int last = arr[0];
    int cnt = 1;
    bool flag = false;
    for (int i = 1; i < n; ++i) {
      if (arr[i] - last >= mid) {
        last = arr[i];
        cnt++;
        if (cnt == c) {
          flag = true;
          break;
        }
      }
    }

    if (flag) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans << "\n";

  return 0;
}