#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for(const auto &ch : s) {
            if(!st.empty() && st.top() == '(' && ch == ')') st.pop();
            else st.push(ch);
        }

        return st.size();
    }
};