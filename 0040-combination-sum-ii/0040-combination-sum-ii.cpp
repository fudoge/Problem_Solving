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
            if (i > idx && candidates[i] == candidates[i - 1]) continue; // 중복 방지
            if (sum + candidates[i] > target) break; // 가지치기

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