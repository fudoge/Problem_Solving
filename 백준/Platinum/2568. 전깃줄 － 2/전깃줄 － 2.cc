#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int n;

vector<int> getLIS(vector<pii> &arr) {
  vector<int> tails;
  vector<int> tails_indices;
  vector<int> parents(n, -1);

  for (int i = 0; i < n; ++i) {
    int pos =
        lower_bound(tails.begin(), tails.end(), arr[i].second) - tails.begin();
    if (pos == tails.size()) {
      tails.push_back(arr[i].second);
      tails_indices.push_back(i);
    } else {
      tails[pos] = arr[i].second;
      tails_indices[pos] = i;
    }
    if (pos != 0) {
      parents[i] = tails_indices[pos - 1];
    }
  }

  int lis_length = tails.size();
  vector<int> lis_idx(lis_length);
  int k = tails_indices.back();
  for (int i = lis_length - 1; i >= 0; --i) {
    lis_idx[i] = k;
    k = parents[k];
  }

  return lis_idx;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  vector<pii> arr(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    arr[i] = {a, b};
  }

  sort(arr.begin(), arr.end());

  auto LIS = getLIS(arr);

  vector<bool> toErase(n, true);
  for (const auto &idx : LIS) {
    toErase[idx] = false;
  }

  cout << n - LIS.size() << "\n";
  for (int i = 0; i < n; ++i) {
    if (toErase[i])
      cout << arr[i].first << "\n";
  }

  return 0;
}