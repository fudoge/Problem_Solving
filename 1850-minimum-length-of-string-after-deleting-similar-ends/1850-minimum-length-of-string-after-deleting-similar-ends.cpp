#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minimumLength(string s) {
        const int n = s.size();
        int left = 0;
        int right = n-1;

        while(left < right) {
            if(s[left] != s[right]) break;
            auto ch = s[left];
            while(left+1 < right && s[left+1] == ch) {
                left++;
            }

            while(left < right-1 && s[right-1] == ch) {
                right--;
            }

            left++;
            right--;
        }

        return right-left+1;
    }
};