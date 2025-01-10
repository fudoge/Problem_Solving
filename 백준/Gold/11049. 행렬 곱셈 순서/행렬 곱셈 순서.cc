#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> dp(501, vector<int>(501, -1)); // 2D DP 배열

int solve(int start, int end, vector<vector<int>> &arr) {
  if (start == end) {
    return 0; // 한 개의 행렬은 연산 필요 없음
  }
  if (dp[start][end] != -1) {
    return dp[start][end];
  }

  int res = INT_MAX;
  for (int i = start; i < end; ++i) {
    int leftCost = solve(start, i, arr);
    int rightCost = solve(i + 1, end, arr);
    int currCost = arr[start][0] * arr[i][1] * arr[end][1]; // 현재 연산 비용
    res = min(res, leftCost + rightCost + currCost);
  }

  return dp[start][end] = res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<vector<int>> arr(n, vector<int>(2));
  for (int i = 0; i < n; ++i) {
    cin >> arr[i][0] >> arr[i][1];
  }

  if (n == 1) {
    cout << "0\n";
  } else if (n == 2) {
    cout << arr[0][0] * arr[0][1] * arr[1][1];
  } else {
    cout << solve(0, n - 1, arr) << "\n";
  }

  return 0;
}