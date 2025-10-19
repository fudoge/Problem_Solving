#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  return 0;
}();
class Solution {
 public:
  char digitAdd(char ch, int x) {
    int ord = ch - '0';
    int newDigit = (ord + x) % 10;
    return '0' + newDigit;
  }
  void rotateRight(string& s, int x) {
    string prefix = s.substr(s.size() - x);
    string suffix = s.substr(0, s.size() - x);
    s = prefix + suffix;
  }
  string findLexSmallestString(string s, int a, int b) {
    unordered_map<string, int> visited;
    string ans = s;
    queue<string> q;
    q.emplace(s);
    while (!q.empty()) {
      string sa = q.front();
      string sb = q.front();
      ans = min(ans, q.front());
      q.pop();

      for (int i = 1; i < sa.size(); i += 2) {
        sa[i] = digitAdd(sa[i], a);
      }
      if (!visited[sa]) {
        visited[sa] = 1;
        q.emplace(sa);
      }

      rotateRight(sb, b);
      if (!visited[sb]) {
        visited[sb] = 1;
        q.emplace(sb);
      }
    }

    return ans;
  }
};