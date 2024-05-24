class Solution {
private:
    const int MOD = 1e9+7;
public:
    int countHomogenous(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int idx = 0;
        long long count = 0;
        while (idx < s.size()) {
            long streak = 1;
            while (idx < s.size() - 1 && s[idx] == s[idx + 1]) {
                streak++;
                idx++;
            }
            count += (streak+1) * streak / 2;
            idx++;
        }
        return count%MOD;
    }
};