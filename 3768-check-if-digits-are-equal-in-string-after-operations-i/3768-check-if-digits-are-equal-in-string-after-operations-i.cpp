#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  return 0;
}();
class Solution {
 public:
  bool hasSameDigits(string s) {
    int last[100];
    for (int i = 0; i < s.size() - 1; i++) {
      last[i] = (((s[i] - '0') + (s[i + 1] - '0')) % 10);
    }

    int cnt = s.size() - 1;
    while (cnt > 2) {
      int curr[100];
      for (int i = 0; i < cnt - 1; i++) {
        curr[i] = ((last[i] + last[i + 1]) % 10);
      }
      memcpy(last, curr, sizeof(curr));
      cnt--;
    }

    return last[0] == last[1];
  }
};