#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1 = 0, zero1 = 0, sum2 = 0, zero2 = 0;
        for(const auto &n1 : nums1) {
            if(n1 == 0) zero1++;
            else sum1 += n1;
        }
        ll min1 = sum1 + zero1;
        for(const auto &n2 : nums2) {
            if(n2 == 0) zero2++;
            else sum2 += n2;
        }
        ll min2 = sum2 + zero2;

        ll diff = min1 - min2; 
        if(diff < 0) {
            if(zero1 == 0) return -1;
            else return min2;
        } else if(diff == 0) {
            return min1;
        } else {
            if(zero2 == 0) return -1;
            else return min1;
        }
    }
};