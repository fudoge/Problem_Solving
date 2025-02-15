#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  getline(cin, s);
  stringstream ss(s);

  deque<string> dq; // has expression
  vector<string> tokens;
  vector<char> ops;
  string temp;
  while (ss >> temp) {
    tokens.push_back(temp);
  }
  if (tokens.size() == 3) {
    cout << s << "\n";
    return;
  }
  for (int i = 0; i < tokens.size(); ++i) {
    // is Number?
    string token = tokens[i];
    if (token[0] >= '0' && token[0] <= '9') {
      dq.push_back(token);
    } else if (token[0] == 'X') {
      auto operandA = dq.back();
      string operandB = tokens[i + 1];
      dq.pop_back();
      i++;
      dq.push_back("(" + operandA + " X " + operandB + ")");
    } else {
      ops.push_back(token[0]);
    }
  }

  int k = 0;
  while (k < ops.size()) {
    auto operandA = dq.front();
    dq.pop_front();
    auto operandB = dq.front();
    dq.pop_front();
    dq.push_front("(" + operandA + " " + ops[k] + " " + operandB + ")");
    k++;
  }

  cout << dq.front().substr(1, dq.front().size() - 2) << "\n";
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}