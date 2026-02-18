class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n & 1;
        n /= 2;
        while(n > 0) {
            if((last ^ (n & 1)) == 0) return false;
            last = last ^ 1;
            n /= 2; 
        }
        return true; 
    }
};