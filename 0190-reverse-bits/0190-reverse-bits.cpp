class Solution {
public:
    int reverseBits(int n) {
        if(n == 0) return 0;
        string b = "";
        while(n > 0) {
            b += '0' + (n & 1);
            n /= 2;
        }

        int ans = 0;
        long long j = 1;
        for(int i = b.size()-1; i >= 0; i--) {
            ans += (b[i]-'0') * j;
            j *= 2;
        }

        return ans << 32 - b.size();
    }
};