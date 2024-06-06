class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int ableOpening = 0;

        for(const char ch : s) {
            if(ch == '(' || ch == '*') ableOpening++;
            else if(ch == ')') {
                if(ableOpening == 0) return false;
                ableOpening--;
            }
            st.push(ch);
        }

        ableOpening = 0;
        while(!st.empty()) {
            char ch = st.top();
            st.pop();

            if(ch == ')' || ch == '*') ableOpening++;
            else if(ch == '(') {
                if(ableOpening == 0) return false;
                ableOpening--;
            }
        }

        return true;
    }
};