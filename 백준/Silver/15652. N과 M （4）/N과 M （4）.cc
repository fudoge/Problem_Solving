#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve(int idx, vector<int> &seq) {
  if (seq.size() == m) {
    for (const auto &element : seq) {
      cout << element << " ";
    }
    cout << "\n";
    return;
  }
  if (idx > n)
    return;
  for (int i = idx; i <= n; ++i) {
    seq.emplace_back(i);
    solve(i, seq);
    seq.pop_back();
  }
}

int main(int argc, char *argv[]) {
  cin >> n >> m;
  vector<int> seq;
  solve(1, seq);

  return 0;
}