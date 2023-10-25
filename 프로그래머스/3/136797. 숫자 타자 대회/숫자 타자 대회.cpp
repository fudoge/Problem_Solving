#include <bits/stdc++.h>
using namespace std;

const int weight[10][10] = {
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};

int dp[100001][10][10];

string nums;

int solve(int idx, int left, int right) {
    if (idx == nums.length()) return 0;
    int& result = dp[idx][left][right];
    if (result != -1) {
        return result;
    }
    
    int target = nums[idx] - '0';

    //손가락 움직일필요 없음
    if (left == target || right == target) {
        return result = 1 + solve(idx + 1, left, right);
    }

    //손가락 움직여보자..
    return result = min(solve(idx + 1, target, right) + weight[left][target]
        , solve(idx + 1, left, target) + weight[right][target]);
}

int solution(string numbers) {
    memset(dp, -1, sizeof(dp));
    nums = numbers;

    return solve(0, 4, 6);
}