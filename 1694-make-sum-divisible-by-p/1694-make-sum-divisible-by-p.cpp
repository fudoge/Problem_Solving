#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(auto &num : nums) sum += num;
        long long remainder = sum % p;
        
        if(remainder == 0) return 0;
        
        unordered_map<long, int> prefix;
        prefix[0] = -1;
        long long current = 0;
        int min_len = nums.size();
        
        for(int i = 0; i < nums.size(); ++i){
            current = (current + nums[i]) % p;
            long long target = (current - remainder + p) % p;
            if(prefix.find(target) != prefix.end()){
                min_len = min(min_len, i - prefix[target]);
            }
            prefix[current] = i;
        }
        
        return min_len < nums.size() ? min_len : -1;
    }
};