#include <bits/stdc++.h>

using namespace std;

vector<int> generateLIS(vector<int> &arr, int n) {
  if (n == 0)
    return {};
  vector<int> tails;
  vector<int> tails_indices;
  vector<int> parents(n, -1);

  for (int i = 0; i < n; ++i) {
    int pos = lower_bound(tails.begin(), tails.end(), arr[i]) - tails.begin();

    if (pos == tails.size()) {
      tails.push_back(arr[i]);
      tails_indices.push_back(i);
    } else {
      tails[pos] = arr[i];
      tails_indices[pos] = i;
    }

    if (pos != 0) {
      parents[i] = tails_indices[pos - 1];
    }
  }

  int lis_length = tails.size();
  vector<int> lis(lis_length);
  int k = tails_indices.back();

  for (int i = lis_length - 1; i >= 0; --i) {
    lis[i] = arr[k];
    k = parents[k];
  }

  return lis;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  vector<int> ans = generateLIS(arr, n);

  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}