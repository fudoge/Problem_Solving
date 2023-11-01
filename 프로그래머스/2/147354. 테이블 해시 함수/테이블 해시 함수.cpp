#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(), data.end(), [col](const auto& a, const auto& b) {
        if (a[col - 1] == b[col - 1]) {
            return a[0] > b[0];
        }
        return a[col - 1] < b[col - 1];
    });

    vector<int> sums;
    int num = 0;

    for (int i = row_begin - 1; i < row_end; i++) {
        int sum = 0;
        for (int j = 0; j < data[i].size(); j++) {
            sum += data[i][j] % (i + 1);
        }
        sums.push_back(sum);
        num ^= sum;
    }

    return num;
}