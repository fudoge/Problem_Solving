class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        const int n = pref.size();
        vector<int> arr(n);
        arr[0] = pref[0];

        for(int i = 1; i < n; i++) {
            arr[i] = pref[i] ^ pref[i-1];
        }

        return arr;
    }
};