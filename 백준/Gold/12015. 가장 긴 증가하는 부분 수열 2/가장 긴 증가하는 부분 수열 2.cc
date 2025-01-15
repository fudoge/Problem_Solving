#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  vector<int> lis;
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(lis.begin(), lis.end(), arr[i]);

    if (it == lis.end()) {
      lis.push_back(arr[i]);
    } else {
      *it = arr[i];
    }
  }

  cout << lis.size() << "\n";

  return 0;
}