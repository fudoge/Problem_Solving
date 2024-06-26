class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int depth = 0;

        for(const auto &ch : s) {
            if(ch == '(') depth++;
            else if(ch == ')') depth--;
            maxDepth = max(maxDepth, depth);
        }

        return maxDepth;
    }
};