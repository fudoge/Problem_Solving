static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i < g.size() && j < s.size()) {
            if(g[i] > s[j]) {
                j++;
                continue;
            }
            cnt++;
            i++;
            j++;
        }

        return cnt;
    }
};