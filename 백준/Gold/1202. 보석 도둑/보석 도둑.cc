#include <bits/stdc++.h>
#include <queue>
#define ll long long
#define pii pair<int, int>
using namespace std;

int n, k;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  vector<pii> gems;
  for (int i = 0; i < n; ++i) {
    int m, v;
    cin >> m >> v;
    gems.push_back({m, v});
  }

  vector<int> bags;
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    bags.emplace_back(c);
  }

  sort(gems.begin(), gems.end());
  sort(bags.begin(), bags.end());
  priority_queue<int> pq;
  ll ans = 0;
  int j = 0;

  for (int i = 0; i < k; ++i) {
    int c = bags[i];
    while (j < n && gems[j].first <= c) {
      pq.push(gems[j].second);
      j++;
    }

    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans << "\n";

  return 0;
}