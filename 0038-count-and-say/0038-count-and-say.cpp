class Solution {
   public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 2; i <= n; i++) {
            string newStr;
            int l = 0;
            for (int r = 0; r < str.size();) {
                while (r < str.size() && str[l] == str[r]) {
                    r++;
                }
                newStr += char(r - l + '0');
                newStr += str[l];
                l = r;
            }
            str = newStr;
        }

        return str;
    }
};