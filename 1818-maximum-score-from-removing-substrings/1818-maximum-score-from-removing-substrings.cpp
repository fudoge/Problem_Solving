class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int aCount = 0;
        int bCount = 0;
        int lesser = min(x, y);
        int ans = 0;

        for(char ch : s) {
            if(ch > 'b') {
                ans += min(aCount, bCount) * lesser;
                aCount = 0;
                bCount = 0;
            } else if(ch == 'a') {
                if(x < y && bCount > 0) {
                    bCount--;
                    ans += y;
                } else {
                    aCount++;
                }
            } else {
                if(x > y && aCount > 0) {
                    aCount--;
                    ans += x;
                } else {
                    bCount++;
                }
            }
        }

        ans += min(aCount, bCount) * lesser;
        return ans;
    }
};