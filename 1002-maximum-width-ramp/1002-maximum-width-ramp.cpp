#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        
        for(int i = 0; i < n; ++i) {
            if(s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        int maxRamp = 0;
        for(int j = n-1; j >= 0; --j) {
            while(!s.empty() && nums[s.top()] <= nums[j]) {
                maxRamp = max(maxRamp, j - s.top());
                s.pop();
            }
        }

        return maxRamp > 0? maxRamp : 0;
    }
};