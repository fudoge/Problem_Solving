class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i+1; j <= n; j++) {
                int root = sqrt(i*i + j*j);
                if(root <= n && root * root == i*i + j*j) {
                    ans += 2;
                }
            }
        } 

        return ans;
    }
};