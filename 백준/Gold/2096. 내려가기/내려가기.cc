#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> last_max(3, 0);
  vector<int> last_min(3, 0);
  vector<int> curr_max(3, 0);
  vector<int> curr_min(3, 0);

  int t1, t2, t3;

  for (int i = 0; i < n; ++i) {
    cin >> t1 >> t2 >> t3;
    curr_max[0] = t1 + max(last_max[0], last_max[1]);
    curr_max[1] = t2 + max(last_max[0], max(last_max[1], last_max[2]));
    curr_max[2] = t3 + max(last_max[1], last_max[2]);

    curr_min[0] = t1 + min(last_min[0], last_min[1]);
    curr_min[1] = t2 + min(last_min[0], min(last_min[1], last_min[2]));
    curr_min[2] = t3 + min(last_min[1], last_min[2]);

    last_max = curr_max;
    last_min = curr_min;
  }

  cout << *max_element(curr_max.begin(), curr_max.end()) << " "
       << *min_element(curr_min.begin(), curr_min.end()) << "\n";

  return 0;
}