#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve(int x, int len, int state, vector<int> &arr) {
  if (len == m) {
    for (const auto &elem : arr) {
      cout << elem << " ";
    }
    cout << "\n";
  }
  for (int i = 1; i <= n; ++i) {
    if (!(state & (1 << i))) {
      state |= (1 << i);
      arr.emplace_back(i);
      solve(i, len + 1, state, arr);
      state &= ~(1 << i);
      arr.pop_back();
    }
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  vector<int> arr;
  for (int i = 1; i <= n; ++i) {
    arr.emplace_back(i);
    int state = (1 << i);
    solve(i, 1, state, arr);
    arr.pop_back();
  }

  return 0;
}