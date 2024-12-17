#include <bits/stdc++.h>

using namespace std;

int t;

unordered_map<char, string> base32 = {
    {' ', "00000"}, {'A', "00001"}, {'B', "00010"}, {'C', "00011"},
    {'D', "00100"}, {'E', "00101"}, {'F', "00110"}, {'G', "00111"},
    {'H', "01000"}, {'I', "01001"}, {'J', "01010"}, {'K', "01011"},
    {'L', "01100"}, {'M', "01101"}, {'N', "01110"}, {'O', "01111"},
    {'P', "10000"}, {'Q', "10001"}, {'R', "10010"}, {'S', "10011"},
    {'T', "10100"}, {'U', "10101"}, {'V', "10110"}, {'W', "10111"},
    {'X', "11000"}, {'Y', "11001"}, {'Z', "11010"}};

string encode(string msg) {
  string res = "";
  for (char ch : msg) {
    res += base32[ch];
  }
  return res;
}

void solve() {
  int r, c;
  cin >> r >> c;
  string msg;
  cin.ignore();
  getline(cin, msg);

  vector<vector<char>> mat(r, vector<char>(c));
  string encoded = encode(msg);

  int tot_length = r * c;
  int minx = 0;
  int miny = 0;
  int maxx = r - 1;
  int maxy = c - 1;
  int k = 0;
  int n = encoded.size();
  while (k < tot_length) {
    for (int i = miny; i <= maxy && k < tot_length; ++i) {
      mat[minx][i] = k < n ? encoded[k] : '0';
      k++;
    }
    minx++;
    if (k >= tot_length)
      break;

    for (int i = minx; i <= maxx && k < tot_length; ++i) {
      mat[i][maxy] = k < n ? encoded[k] : '0';
      k++;
    }
    maxy--;
    if (k >= tot_length)
      break;

    for (int i = maxy; i >= miny && k < tot_length; --i) {
      mat[maxx][i] = k < n ? encoded[k] : '0';
      k++;
    }
    maxx--;

    if (k >= tot_length)
      break;

    for (int i = maxx; i >= minx && k < tot_length; --i) {
      mat[i][miny] = k < n ? encoded[k] : '0';
      k++;
    }
    miny++;
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << mat[i][j];
    }
  }
  cout << "\n";
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}