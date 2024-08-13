#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
private:
    int n;
    int target;
    vector<vector<int>> result;

public:
    void solve(int idx, int sum, vector<int>& combination, vector<int>& candidates) {
        if(sum == target) {
            result.push_back(combination);
            return;
        }

        for(int i = idx; i < n; i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (sum + candidates[i] > target) break;

            combination.push_back(candidates[i]);
            solve(i+1, sum + candidates[i], combination, candidates);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        solve(0, 0, combination, candidates);
        return result;
    }
};