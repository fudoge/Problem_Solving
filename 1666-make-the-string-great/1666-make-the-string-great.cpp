class Solution {
public:
    string makeGood(string s) {
        while(true) {
            string temp = "";
            bool flag = false;
            for(int i = 0; i < s.size(); i++) {
                if(i == s.size()-1) {
                    temp += s[i];
                    continue;
                }
                
                if((s[i] + 32 == s[i+1]) || (s[i+1] + 32 == s[i])) {
                    flag = true;
                    i++;
                    continue;
                }
                temp += s[i];
            }
            s = temp;

            if(!flag) break;
        }

        return s;
    }
};