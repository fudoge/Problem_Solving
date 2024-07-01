#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int streak = 0;
        for(const auto& x : arr) {
            if(x%2 == 1) {
                if(++streak == 3) return true;
            } else {
                streak = 0;
            }
    
        }
        return false;
    }
};