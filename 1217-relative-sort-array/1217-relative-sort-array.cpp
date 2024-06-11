#pragma GCC optimize("03", "unroll-loops");

static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i + 1;
        }

        sort(arr1.begin(), arr1.end(), [&mp](int a, int b) {
            if (mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
                return mp[a] < mp[b];
            } else if (mp.find(a) != mp.end()) {
                return true;
            } else if (mp.find(b) != mp.end()) {
                return false; 
            } else {
                return a < b;
            }
        });

        return arr1;
    }
};
