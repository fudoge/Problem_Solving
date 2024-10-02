#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
private:
    int binSearch(vector<int>& arr, int num) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == num) return mid;

            if (arr[mid] > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted(arr.begin(), arr.end());

        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        vector<int> ans;
        for (const auto& num : arr) {
            ans.push_back(binSearch(sorted, num) + 1);
        }

        return ans;
    }
};