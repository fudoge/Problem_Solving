class Solution {
public:
    int minLength(string s) {
        while(true) {
            bool flag = true;
            int n = s.size();
            string newStr = "";
            for(int i = 0; i < n; ++i) {
                if((i < n-1 && s[i] == 'A' && s[i+1] == 'B') || (s[i] == 'C' && s[i+1] == 'D')) {
                    i++;
                    flag = false;
                } else {
                    newStr += s[i];
                }
            }
            if(flag) break;
            s = newStr;
        }
        return s.size();
    }
};