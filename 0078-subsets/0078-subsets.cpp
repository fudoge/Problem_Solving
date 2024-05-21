class Solution {
private:
    vector<vector<int>> ans;
    int n;
public:
    void dfs(vector<int>& nums, vector<int> &arr, int idx) {

        ans.push_back(arr);
        for(int i = idx; i < n; i++) {
            arr.push_back(nums[i]);
            dfs(nums, arr, i+1);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> s = {};
        dfs(nums, s, 0);
        return ans;
    }
};