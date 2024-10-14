class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        long long ans = 0;

        for(int num : nums) {
            maxHeap.push(num);
        }

        for(int i = 0; i < k; ++i) {
            int x = maxHeap.top();
            maxHeap.pop();
            ans += x;
            x = ceil((double)x/3);
            maxHeap.push(x);
        }

        return ans;
    }
};