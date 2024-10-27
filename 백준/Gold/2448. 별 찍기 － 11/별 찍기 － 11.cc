#include <bits/stdc++.h>

using namespace std;

int len;
void scaleup(int height, vector<string> &sample) {
  for (int i = 0; i < height / 2; ++i) {
    string temp = "";
    temp += sample[i] + " " + sample[i];
    sample.emplace_back(temp);
    sample[i] = string(height / 2, ' ') + sample[i] + string(height / 2, ' ');
  }
}

void solve(int n) {

  vector<string> sample = {"  *  ", " * * ", "*****"};

  int height = 6;
  while (height <= n) {
    scaleup(height, sample);
    height *= 2;
  }
  for (int i = 0; i < n; ++i) {
    cout << sample[i] << "\n";
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  len = n * 2 - 1;
  solve(n);
  return 0;
}