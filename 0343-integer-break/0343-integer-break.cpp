class Solution {
public:
    int integerBreak(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(n <= 3) return n-1;

        if(n%3 == 0) {
            return (int)pow(3, n/3);
        } else if(n%3 == 1) {
            return (int)pow(3, (n/3)-1) * 4;
        } else {
            return (int)pow(3, n/3)*2;
        }
    }
};