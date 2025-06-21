#pragma GCC optimize("O3", "unroll-loops");
static const int init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(char ch : word)
            freq[ch-'a']++;

        sort(freq.begin(), freq.end());
        vector<int> pref(26, 0);
        pref[0] = freq[0];
        for(int i = 1; i < 26; i++) 
            pref[i] = pref[i-1] + freq[i];

        int right = 0;
        int ans = INT_MAX;
        for(int left = 0; left < 26; left++) {
            while(right < 26 && freq[right] - freq[left] <= k) 
                right++;
            int leftDel = left > 0? pref[left-1]:0;

            int rightDel = right < 26? (pref[25] - pref[right-1]) - (26 - right) * (freq[left] + k):0;

            ans = min(ans, leftDel + rightDel);
        }
        return ans;
    }
};