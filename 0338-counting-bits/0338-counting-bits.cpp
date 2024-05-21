class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> table(n+1, 0);

        for(int i = 1; i <= n; i++) {
            table[i] = table[i >> 1] + (i & 1);
        }

        return table;                
    }
};