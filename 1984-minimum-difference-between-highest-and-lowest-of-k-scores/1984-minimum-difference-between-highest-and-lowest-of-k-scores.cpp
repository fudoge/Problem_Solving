#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using pii = pair<int, int>;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;

        priority_queue<pii> maxHeap;
        priority_queue<pii, vector<pii>, greater<>> minHeap;
        for(int i = 0; i < k; i++) {
            maxHeap.emplace(nums[i], i);
            minHeap.emplace(nums[i], i);
            ans = maxHeap.top().first - minHeap.top().first;
        }
        for(int i = k; i < n; i++) {
            maxHeap.emplace(nums[i], i);
            minHeap.emplace(nums[i], i);
            while(!maxHeap.empty() && maxHeap.top().second <= i-k) {
                maxHeap.pop();
            }
            while(!minHeap.empty() && minHeap.top().second <= i-k) {
                minHeap.pop();
            }
            ans = min(ans, maxHeap.top().first - minHeap.top().first);
        }
        return ans;
    }
};