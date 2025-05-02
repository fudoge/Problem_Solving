#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    pair<int, int> find_neighbors(vector<pair<int, char>> &nums, int target) {
        int res = -1;
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid].first < target) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return {res, res + 1};
    }

    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<pair<int, char>> tilted;

        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') tilted.emplace_back(i, dominoes[i]);
        }

        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') continue;
            auto [left, right] = find_neighbors(tilted, i);

            if (left == -1) {
                if (right < tilted.size() && tilted[right].second == 'L')
                    dominoes[i] = 'L';
            } else if (right == tilted.size()) {
                if (tilted[left].second == 'R')
                    dominoes[i] = 'R';
            } else {
                char leftChar = tilted[left].second;
                char rightChar = tilted[right].second;
                int leftDist = i - tilted[left].first;
                int rightDist = tilted[right].first - i;

                if (leftChar == 'R' && rightChar == 'L') {
                    if (leftDist < rightDist) dominoes[i] = 'R';
                    else if (rightDist < leftDist) dominoes[i] = 'L';
                } else if (leftChar == 'L' && rightChar == 'L') {
                    dominoes[i] = 'L';
                } else if (leftChar == 'R' && rightChar == 'R') {
                    dominoes[i] = 'R';
                }
            }
        }

        return dominoes;
    }
};