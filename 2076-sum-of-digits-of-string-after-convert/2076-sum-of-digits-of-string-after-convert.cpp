#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    string convert(string s) {
        string num = "";
        for(char ch : s) {
            int x = ch - 'a' + 1;
            num += to_string(x);
        }

        return num;
    }

    int getLucky(string s, int k) {
        string converted = convert(s);
        for(int i = 0; i < k; i++) {
            long long ans = 0;
            for(char ch : converted) {
                ans += ch - '0';
            }
            converted = to_string(ans);
        }
        return stoi(converted);
    }
};