class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                int j = st.top();
                st.pop();
                reverse(s.begin() + j + 1, s.begin() + i);
            }
        }

        string res = "";
        for(const auto &ch : s) {
            if(ch != '(' && ch != ')') {
                res += ch;
            }
        }

        return res;
    }
};