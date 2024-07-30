class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int ans = 0;

        for(const char &ch : s) {
            if(ch == 'b') bCount++;
            else if(ch == 'a') {
                ans = min(ans+1, bCount);
            }
        }

        return ans;
    }
};