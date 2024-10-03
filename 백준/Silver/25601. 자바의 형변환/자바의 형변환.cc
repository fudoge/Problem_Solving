#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  unordered_map<string, string> mp;

  for (int i = 0; i < n - 1; ++i) {
    string A, B;
    cin >> A >> B;

    mp[A] = B;
  }
  string classA, classB;
  cin >> classA >> classB;
  string curr = classA;
  while (mp[curr] != "") {
    if (mp[curr] == classB) {
      cout << "1\n";
      return 0;
    }
    curr = mp[curr];
  }

  curr = classB;
  while (mp[curr] != "") {
    if (mp[curr] == classA) {
      cout << "1\n";
      return 0;
    }
    curr = mp[curr];
  }

  cout << "0\n";

  return 0;
}