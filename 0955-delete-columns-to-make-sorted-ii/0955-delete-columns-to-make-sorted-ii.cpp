class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;

        vector<bool> sorted(n-1, false);
        for(int j = 0; j < m; j++) {
            vector<bool> temp = sorted;
            bool flag = false;
            for(int i = 0; i < n-1; i++) {
                if(!sorted[i]) {
                    if(strs[i][j] > strs[i+1][j]) {
                        flag = true;
                        break;
                    } else if(strs[i][j] < strs[i+1][j]) {
                        temp[i] = true;
                    }
                }
            }

            if(flag) {
                ans++;
            } else {
                sorted = temp;
            }
        }

        return ans;
    }
};