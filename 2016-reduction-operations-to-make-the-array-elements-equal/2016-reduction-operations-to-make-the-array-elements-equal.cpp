class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        const int n = nums.size();
        int opsCount = 0;
        int ops = 0;

        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) ops++;
            opsCount += ops;            
        }
        return opsCount;
    }
};