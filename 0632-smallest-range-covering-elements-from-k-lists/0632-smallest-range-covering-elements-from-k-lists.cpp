#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

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
        unordered_map<int, int> count;
        int left = 0, minWidth = INT_MAX;
        int rangeStart = -1, rangeEnd = -1;
        int uniqueLists = 0;

        for(int right = 0; right < arr.size(); ++right) {
            int rightVal = arr[right].first;
            int listIdx = arr[right].second;

            if(count[listIdx] == 0) {
                uniqueLists++;
            }
            count[listIdx]++;

            while(uniqueLists == n && left <= right) {
                int leftVal = arr[left].first;
                int currRange = rightVal - leftVal;

                if(currRange < minWidth) {
                    minWidth = currRange;
                    rangeStart = leftVal;
                    rangeEnd = rightVal;
                }

                int leftListIdx = arr[left].second;
                count[leftListIdx]--;
                if(count[leftListIdx] == 0) {
                    uniqueLists--;
                }
                left++;
            }
        }

        return {rangeStart, rangeEnd};
    }
};