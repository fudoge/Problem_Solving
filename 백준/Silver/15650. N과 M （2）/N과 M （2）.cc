#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve(int idx, vector<int> &seq, vector<int> &arr) {
  if (seq.size() == m) {
    for (int i = 0; i < m; ++i) {
      cout << seq[i] << " ";
    }
    cout << "\n";
    return;
  }
  if (idx >= n)
    return;

  for (int i = idx; i < n; ++i) {
    seq.emplace_back(arr[i]);
    solve(i + 1, seq, arr);
    seq.pop_back();
  }
}

int main(int argc, char *argv[]) {
  cin >> n >> m;
  vector<int> arr(n, 1);
  for (int i = 1; i < n; ++i) {
    arr[i] += arr[i - 1];
  }

  vector<int> seq;
  solve(0, seq, arr);

  return 0;
}