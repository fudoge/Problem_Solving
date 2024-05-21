class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        if (n < 27) {
            return string(1, 65 + (n - 1) % 26);
        }
        string c = "";
        while(n > 0) {
            if(n % 26 == 0) {
                c+= 90;
                n -= 1;
            } else {
                c += 65 + n%26 - 1;
            }
            n /= 26;
        }
        reverse(c.begin(), c.end());

        return c;
    }
};