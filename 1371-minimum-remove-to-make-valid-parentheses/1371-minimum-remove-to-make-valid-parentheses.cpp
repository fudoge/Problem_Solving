class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp = "";
        int opening = 0;

        for(const auto &ch : s) {
            if(ch == '(') opening++;
            else if(ch == ')') {
                if(opening > 0) opening--;
                else continue;
            }
            temp += ch;
        }
        s.clear();
        opening = 0;
        
        for(int i = temp.size()-1; i >= 0; i--) {
            if(temp[i] == ')') opening++;
            else if(temp[i] == '(') {
                if(opening > 0) opening--;
                else continue;
            }

            s += temp[i];
        }

        reverse(s.begin(), s.end());
        return s;
    }
};