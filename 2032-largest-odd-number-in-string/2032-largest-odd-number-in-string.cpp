static const int __ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    string largestOddNumber(string num) {
        const int n = num.size();
        for(int i = n-1; i >=0 ; i--) {
            if((num[i]-'0') % 2 == 1) {
                return num.substr(0, i+1);
            }
        }

        return "";
    }
};