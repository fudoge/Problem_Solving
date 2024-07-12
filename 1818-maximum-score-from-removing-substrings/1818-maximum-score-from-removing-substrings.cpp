class Solution {
public:
    int removePairs(char firstChar, char secondChar, int point, string &str) {
        stack<char> st;
        int res = 0;
        for (int i = 0; i < str.size(); i++) {
            if (!st.empty() && st.top() == firstChar && str[i] == secondChar) {
                st.pop();
                res += point;
            } else {
                st.push(str[i]);
            }
        }

        str.clear();
        while (!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return res;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if (x >= y) {
            ans += removePairs('a', 'b', x, s);
            ans += removePairs('b', 'a', y, s);
        } else {
            ans += removePairs('b', 'a', y, s);
            ans += removePairs('a', 'b', x, s);
        }

        return ans;
    }
};