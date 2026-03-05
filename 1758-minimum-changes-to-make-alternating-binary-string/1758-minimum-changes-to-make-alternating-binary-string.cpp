class Solution {
public:
    int calc(string &s, int start) {
        int res = 0;
        int goal = start;
        for(char ch : s) {
            int curr = ch - '0';
            if(curr != goal) res++;
            goal ^= 1;
        }

        return res;
    }
    int minOperations(string s) {
        int ops = calc(s, 0);
        int n = s.size();
        return min(ops, n - ops);
    }
};