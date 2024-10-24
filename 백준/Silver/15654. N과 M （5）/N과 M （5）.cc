#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve(vector<int> &seq, vector<int> &arr) {
  if (seq.size() == m) {
    for (const auto &element : seq) {
      cout << element << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; ++i) {

    if (find(seq.begin(), seq.end(), arr[i]) == seq.end()) {
      seq.emplace_back(arr[i]);
      solve(seq, arr);
      seq.pop_back();
    }
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());
  vector<int> seq;
  solve(seq, arr);

  return 0;
}