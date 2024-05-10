class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                ans.push_back({arr[i], arr[j]});
            }
        }

        sort(ans.begin(), ans.end(), [](const auto &a, const auto &b){
            return double(a[0])/a[1] < double(b[0])/b[1];
        });

        return ans[k-1];
    }
};
