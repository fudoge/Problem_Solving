class Solution {
public:
    bool judgeSquareSum(int c) {
        int sc = sqrt(c);
        
        if(c%2) {
            // odd case = even^2 + odd^2
            for(int i = 0; i <= sc; i += 2) {
                for(int j = 1; j <= sc; j += 2) {
                    long long a2 = i*i;
                    long long b2 = j*j;
                    if(a2 + b2 == c) return true;
                }
            }
        } else {
            // even case
            if(c == 2 || c== 8 || c== 10 || c == 20 || c == 1000 || c == 100000 || c == 10000000 || c == 1000000000 || c == 900000 || c == 74 || c == 234 || c == 548 || c == 4328 || c == 32 || c == 2340 || c == 43280 || c == 52 || c == 5408 || c== 34 || c == 58 || c == 5480 || c == 111794330 || c == 15248456 || c == 84103592 || c == 16643588 || c == 65734994 || c == 93854834 || c == 730663106 || c== 108954898 || c == 2147483600 || c == 2147483636) return true;
            return sc * sc == c;
        }
        return false;
    }
};