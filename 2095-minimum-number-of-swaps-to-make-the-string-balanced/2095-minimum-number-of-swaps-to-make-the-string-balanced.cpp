class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;

        for(int i = 0; i < s.size(); ++i) {
            if(stk.empty() || s[i] == '[') stk.push(s[i]);
            else if(stk.top() == '[') stk.pop();
        }
        return stk.size()/2;
    }
};