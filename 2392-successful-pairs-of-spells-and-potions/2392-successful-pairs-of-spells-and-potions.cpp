#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = m - binSearch(potions, success, spells[i]);
        }

        return res;
    }

    int binSearch(vector<int>& potions, ll success, ll spell) {
        int l = 0, r = potions.size()-1;
        int res = potions.size();
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(potions[mid] * spell >= success) {
                res = mid;
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};