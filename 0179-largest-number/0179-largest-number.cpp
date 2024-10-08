#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](auto &a, auto &b){
            string A = to_string(a);
            string B = to_string(b);
            return A + B > B + A;
        });

        if(nums[0] == 0) return "0";

        string ans = "";
        for(auto &num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};