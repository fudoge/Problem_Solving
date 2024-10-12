#include <bits/stdc++.h>

using namespace std;

struct comp {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second)
      return a.first < b.first;
    return a.second < b.second;
  }
};

int n;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;

  int left, right;
  vector<pair<int, int>> meetings(n);
  for (int i = 0; i < n; ++i) {
    cin >> left >> right;
    meetings[i] = {left, right};
  }
  sort(meetings.begin(), meetings.end(), comp());

  int endTime = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (endTime <= meetings[i].first) {
      endTime = meetings[i].second;
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}