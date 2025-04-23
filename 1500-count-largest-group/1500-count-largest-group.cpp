#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++) {
            int x = i;
            int d = 0;
            while(x > 0) {
                d += x%10; 
                x /= 10;
            }
            mp[d]++;
        } 

        int largest = 0;
        int ans = 0;
        for(const auto &[k, v] : mp) {
            if(v > largest) {
                largest = v;
                ans = 1;
            } else if(v == largest) {
                ans++;
            }
        }

        return ans;
    }
};