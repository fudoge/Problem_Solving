#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int best = 0;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') {
                best++;
            }
        } 
        
        int ans = 0;
        int curr = best;
        for(int i = 1; i <= n; i++) {
            if(customers[i-1] == 'Y') {
                curr--;
            } else {
                curr++;
            }
            if(curr < best) {
                best = curr;
                ans = i;
            }
        }

        return ans;
    }
};