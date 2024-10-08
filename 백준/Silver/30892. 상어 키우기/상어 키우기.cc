#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k, t;
  cin >> n >> k >> t;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  long long shark = t;
  for (int i = 0; i < k; ++i) {
    int idx =
        distance(arr.begin(), upper_bound(arr.begin(), arr.end(), shark)) - 1;
    while (idx >= 0 && arr[idx] == shark)
      idx--;
    if (idx < 0)
      break;

    shark += arr[idx];
    arr.erase(arr.begin() + idx);
  }

  cout << shark << "\n";
  return 0;
}