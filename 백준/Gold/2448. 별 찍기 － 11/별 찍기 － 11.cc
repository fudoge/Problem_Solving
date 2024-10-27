#include <bits/stdc++.h>

using namespace std;

int len;
void scaleup(int height, vector<string> &shape) {
  for (int i = 0; i < height / 2; ++i) {
    string temp = "";
    temp += shape[i] + " " + shape[i];
    shape.emplace_back(temp);
    shape[i] = string(height / 2, ' ') + shape[i] + string(height / 2, ' ');
  }
}

void solve(int n) {

  vector<string> shape = {"  *  ", " * * ", "*****"};

  int height = 6;
  while (height <= n) {
    scaleup(height, shape);
    height *= 2;
  }
  for (int i = 0; i < n; ++i) {
    cout << shape[i] << "\n";
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  len = n * 2 - 1;
  solve(n);
  return 0;
}