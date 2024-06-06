class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) return "0";
        stack<char> st;
        
        for(const char &digit : num) {
            while(!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string res;
        
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        while(res[0] == '0') res.erase(0, 1);

        return res.size() == 0? "0" : res;
    }
};