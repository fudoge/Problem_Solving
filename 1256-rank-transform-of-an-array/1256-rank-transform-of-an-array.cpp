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