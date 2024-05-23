class Solution {
private:
    int ans;
    int k;
public:
    bool isbeautifulElement(vector<int>& nums, vector<int> &subset, int i) {
        for(const int element : subset) {
            if(nums[i] - element == k) return false;
        }
        return true;
    }
    void solve(vector<int>& nums, vector<int> &subset, int idx) {
        ans++;
        if(idx >= nums.size()) return;

        for(int i = idx; i < nums.size(); i++) {
            if(isbeautifulElement(nums, subset, i)) {
                subset.push_back(nums[i]);
                solve(nums, subset, i+1);
                subset.pop_back();
            }
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        this -> k = k;
        int n = nums.size();
        ans = 0;
        vector<int> subset = {};
        for(int i = 0; i < n; i++) {
            subset.push_back(nums[i]);
            solve(nums, subset, i+1);
            subset.pop_back();
        }
        return ans;
    }
};