class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;
        queue<char> q;
        bool flag = false;
        int idx = 0;
        while(idx < word.size()) {
            st.push(word[idx]);
            if(word[idx] == ch) {
                flag = true;
                break;
            }
            idx++;
        }
        if(!flag) return word;
        idx++;
        while(idx < word.size()) {
            q.push(word[idx]);
            idx++;
        }

        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        while(!q.empty()) {
            res += q.front();
            q.pop();
        }

        return res;
    }
};