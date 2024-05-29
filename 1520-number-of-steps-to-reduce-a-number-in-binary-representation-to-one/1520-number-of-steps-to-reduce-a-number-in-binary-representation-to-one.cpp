class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        int carry = 0;

        for (int i = n - 1; i > 0; --i) {
            if ((s[i] - '0' + carry) % 2 == 0) { 
                ans++; 
            } else {
                carry = 1;
                ans += 2;
            }
        }
        return ans + carry; // if carry is 1, we need an extra step to add 1 to the most significant bit
    }
};
