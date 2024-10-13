class Solution {
private:
    pair<int, int> minMax(vector<int>& represents) {
        return {*min_element(represents.begin(), represents.end()), *max_element(represents.begin(), represents.end())};
    }
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> arr;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            for(const auto &x : nums[i]) {
                arr.push_back({x, i});
            }
        }

        sort(arr.begin(), arr.end());
        vector<int> represents(n);
        for(int i = 0; i < n; ++i) {
            represents[i] = nums[i][0];
        }

        int m = arr.size();
        int minWidth = INT_MAX;
        int rangeStarts = *min_element(represents.begin(), represents.end());
        vector<int> ans(2);
        for(int i = 0; i < m; ++i) {
            represents[arr[i].second] = arr[i].first;
            auto minAndMax = minMax(represents);
            int gap = abs(minAndMax.second - minAndMax.first);
            if(gap < minWidth || minAndMax.first < rangeStarts) {
                ans = {minAndMax.first, minAndMax.second};
                minWidth = gap;
                rangeStarts = minAndMax.first;
            }
        }

        return ans;
    }
};