#include <bits/stdc++.h>

using namespace std;

int isDividedBy253(string &karylNum, int n) {
  if ((karylNum[n - 1] - '0') % 2 == 0)
    return 2;
  if (karylNum[n - 1] == '5')
    return 5;

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += karylNum[i] - '0';
  }

  if (sum % 3 == 0)
    return 3;
  return -1;
}

void solve(string num) {
  int n = num.size();
  if (n == 1) {
    cout << "4 2\n";
  }
  string karylNum(num);

  int count = 0;
  for (int digit = n - 1; digit > 0; --digit) {
    for (char newDigit = '0'; newDigit <= '9'; ++newDigit) {
      if (newDigit == num[digit])
        continue;
      karylNum[digit] = newDigit;

      int res = isDividedBy253(karylNum, n);
      if (res != -1) {
        cout << karylNum << " " << res << "\n";
        ++count;
        if (count >= n)
          return;
      }
    }
    karylNum[digit] = num[digit];
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  vector<string> nums(t);
  string temp;
  for (int i = 0; i < t; ++i) {
    cin >> temp;
    cin >> nums[i];
  }

  for (int i = 0; i < t; ++i) {
    solve(nums[i]);
  }
  return 0;
}